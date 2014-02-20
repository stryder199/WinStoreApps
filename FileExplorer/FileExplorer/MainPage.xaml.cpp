//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace FileExplorer;
using namespace FileExplorer::Data;

using namespace Platform;
using namespace Platform::Collections;
using namespace concurrency;
using namespace Windows::Data::Xml::Dom;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	bool result;

	InitializeComponent();
	FSDataSource^ fsDataSource = ref new FSDataSource();
	itemsViewSource->Source = fsDataSource->Groups;

	myPCMap = ref new Map<String^, String^>();
	recentsVec = ref new Vector<NamePathPair>();
	favoritesVec = ref new Vector<NamePathPair>();

	result = ConstructSideBar();
	if (!result)
	{
		int i;
	}
}

bool FileExplorer::MainPage::ConstructSideBar()
{
	bool result;

	result = LoadMyPCMap();
	if (!result)
	{
		return false;
	}

	StorageFolder ^localFolder = ApplicationData::Current->LocalFolder;

	create_task(localFolder->GetFileAsync("config.xml"))
		.then([this](StorageFile^ configFile)
	{
		create_task(XmlDocument::LoadFromFileAsync(configFile))
			.then([this](XmlDocument^ xmlConfigFile)
		{
			bool result;
			
			result = LoadRecents(xmlConfigFile);
			if (!result)
			{
				int i;
			}

			result = LoadFavorites(xmlConfigFile);
			if (!result)
			{
				int i;
			}

			ListBox^ favoritestitleLB = GetSideBarListBox();
			Button^ favoritesBut = GetSideBarButton();
			favoritesBut->Content = "> Favorites";

			favoritestitleLB->Items->Append(favoritesBut);
			sideMenuListBox->Items->Append(favoritestitleLB);

			ListBox^ favoritesLB = GetSideBarListBox();
			favoritesLB->Items->Append(favoritesLB);

			for each(NamePathPair favoritesPair in favoritesVec->GetView())
			{
				Button^ favoritesBut = GetSideBarButton();
				favoritesBut->Content = favoritesPair.name;
				favoritesLB->Items->Append(favoritesBut);
			}

			ListBox^ recentTitleLB = GetSideBarListBox();
			Button^ recentBut = GetSideBarButton();
			recentBut->Content = "> Recent";

			recentTitleLB->Items->Append(recentBut);
			sideMenuListBox->Items->Append(recentTitleLB);

			ListBox^ recentsLB = GetSideBarListBox();
			recentTitleLB->Items->Append(recentsLB);

			for each(NamePathPair recentsPair in recentsVec->GetView())
			{
				Button^ recentsBut = GetSideBarButton();
				recentsBut->Content = recentsPair.name;
				recentsLB->Items->Append(recentsBut);
			}

			ListBox^ mypcTitleLB = GetSideBarListBox();
			Button^ mypcBut = GetSideBarButton();
			mypcBut->Content = "> My PC";

			mypcTitleLB->Items->Append(mypcBut);
			sideMenuListBox->Items->Append(mypcTitleLB);

			ListBox^ mypcLB = GetSideBarListBox();
			mypcTitleLB->Items->Append(mypcLB);

			IIterator<IKeyValuePair<String^, String^>^>^ it;

			for (it = myPCMap->GetView()->First(); it->HasCurrent != false; it->MoveNext())
			{
				Button^ mypcBut = GetSideBarButton();
				mypcBut->Content = it->Current->Key;
				mypcLB->Items->Append(mypcBut);
			}

			ListBox^ networkLB = GetSideBarListBox();
			Button^ networkBut = GetSideBarButton();
			networkBut->Content = "> Network";

			networkLB->Items->Append(networkBut);
			sideMenuListBox->Items->Append(networkLB);
		});
	});

	return true;
}

ListBox^ FileExplorer::MainPage::GetSideBarListBox()
{
	ListBox^ listBox = ref new ListBox();
	listBox->Background = ref new SolidColorBrush();
	listBox->Foreground = ref new SolidColorBrush();
	listBox->BorderBrush = ref new SolidColorBrush();

	listBox->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
	listBox->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;
	listBox->HorizontalContentAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;

	listBox->IsDoubleTapEnabled = false;
	listBox->IsHoldingEnabled = false;
	listBox->IsRightTapEnabled = false;
	listBox->IsHitTestVisible = false;

	listBox->BorderThickness = 0;

	return listBox;
}

Button^ FileExplorer::MainPage::GetSideBarButton()
{
	Button^ button = ref new Button();

	button->Background = SideMenuColor;
	button->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Black);
	button->BorderBrush = ref new SolidColorBrush();

	button->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
	button->VerticalContentAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
	button->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;
	button->HorizontalContentAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;

	button->IsDoubleTapEnabled = false;
	button->IsHoldingEnabled = false;
	button->IsRightTapEnabled = false;
	button->IsHitTestVisible = false;

	button->BorderThickness = 0;

	button->Width = 257;

	button->FontSize = 20;

	button->Content = "UNINITIALIZED";

	return button;
}

bool FileExplorer::MainPage::LoadMyPCMap()
{
	myPCMap->Insert("Desktop", "C:\\Users\\Stryder\\Desktop");
	myPCMap->Insert("Documents", "C:\\Users\\Stryder\\Documents");
	myPCMap->Insert("Pictures", "C:\\Users\\Stryder\\Pictures");
	myPCMap->Insert("Downloads", "C:\\Users\\Stryder\\Downloads");
	myPCMap->Insert("Music", "C:\\Users\\Stryder\\Music");
	myPCMap->Insert("Videos", "C:\\Users\\Stryder\\Videos");
	myPCMap->Insert("Local Disk (C:)", "C:\\");
	myPCMap->Insert("Data (D:)", "D:\\");
}

bool FileExplorer::MainPage::LoadRecents(XmlDocument^ xmlConfigFile)
{
	IXmlNode^ recentsRoot = xmlConfigFile->SelectSingleNode("/config/recents");
	XmlNodeList^ recentsList = recentsRoot->SelectNodes("recent");

	for each(IXmlNode^ node in recentsList)
	{
		String^ name = node->SelectSingleNode("name")->InnerText;
		String^ path = node->SelectSingleNode("path")->InnerText;
		NamePathPair recent;
		recent.name = name;
		recent.path = path;
		recentsVec->Append(recent);
	}
}

bool FileExplorer::MainPage::LoadFavorites(XmlDocument^ xmlConfigFile)
{
	IXmlNode^ favortiesRoot = xmlConfigFile->SelectSingleNode("/config/favorites");
	XmlNodeList^ favoritesList = favortiesRoot->SelectNodes("favorite");

	for each(IXmlNode^ node in favoritesList)
	{
		String^ name = node->SelectSingleNode("name")->InnerText;
		String^ path = node->SelectSingleNode("path")->InnerText;
		NamePathPair favorite;
		favorite.name = name;
		favorite.path = path;
		favoritesVec->Append(favorite);
	}
}

void FileExplorer::MainPage::TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}
