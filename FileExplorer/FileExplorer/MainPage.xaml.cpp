//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace FileExplorer;

using namespace Platform;
using namespace Windows::Storage;
using namespace Windows::Storage::BulkAccess;
using namespace Windows::Storage::FileProperties;
using namespace Windows::Storage::Search;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();

	StorageFolder^ picturesFolder = KnownFolders::PicturesLibrary;
	
	QueryOptions^ queryOptions = ref new QueryOptions();
	queryOptions->FolderDepth = FolderDepth::Deep;
	queryOptions->IndexerOption = IndexerOption::UseIndexerWhenAvailable;

	StorageItemQueryResult^ folderQueryResult = picturesFolder->CreateItemQueryWithOptions(queryOptions);

	FileInformationFactory^ ff = ref new FileInformationFactory(folderQueryResult, ThumbnailMode::ListView);
	
	IAsyncOperation<IVectorView<IStorageItemInformation^>^>^ filesystemQueryAsync = ff->GetItemsAsync();

	IVectorView<IStorageItemInformation^>^ fsItemVec = filesystemQueryAsync->GetResults();



}


void FileExplorer::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void FileExplorer::MainPage::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}
