//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace FileExplorer
{
	public value struct NamePathPair
	{

	public:
		Platform::String^ name;
		Platform::String^ path;
	};

	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		bool ConstructSideBar();
		bool LoadMyPCMap();
		bool LoadRecents(Windows::Data::Xml::Dom::XmlDocument^ config);
		bool LoadFavorites(Windows::Data::Xml::Dom::XmlDocument^ config);

		Windows::UI::Xaml::Controls::ListBox^ GetSideBarListBox();
		Windows::UI::Xaml::Controls::Button^ GetSideBarButton();

		void TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);

		Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ myPCMap;
		Windows::Foundation::Collections::IVector<NamePathPair>^ recentsVec;
		Windows::Foundation::Collections::IVector<NamePathPair>^ favoritesVec;
	};
}
