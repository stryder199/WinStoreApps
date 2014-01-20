//
// SampleDataSource.cpp
// Implementation of the SampleDataSource, SampleDataGroup, SampleDataItem, and SampleDataCommon classes
//

#include "pch.h"
#include<stdlib.h>

using namespace FileExplorer::Data;

using namespace Platform;
using namespace Platform::Collections;
using namespace concurrency;
using namespace Windows::ApplicationModel::Resources::Core;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Storage;
using namespace Windows::Storage::BulkAccess;
using namespace Windows::Storage::FileProperties;
using namespace Windows::Storage::Search;

//
// FSDataItem
//

FSDataItem::FSDataItem(String^ uniqueId, String^ filename, String^ filesize) :
	_uniqueId(uniqueId),
	_filename(filename),
	_filesize(filesize)
{
}

String^ FSDataItem::UniqueId::get()
{
	return _uniqueId;
}

String^ FSDataItem::Filename::get()
{
	return _filename;
}

String^ FSDataItem::FileSize::get()
{
	return _filesize;
}

Windows::UI::Xaml::Data::ICustomProperty^ FSDataItem::GetCustomProperty(Platform::String^ name)
{
	return nullptr;
}

Windows::UI::Xaml::Data::ICustomProperty^ FSDataItem::GetIndexedProperty(Platform::String^ name, Windows::UI::Xaml::Interop::TypeName type)
{
	return nullptr;
}

Platform::String^ FSDataItem::GetStringRepresentation()
{
	return Filename;
}

Windows::UI::Xaml::Interop::TypeName FSDataItem::Type::get()
{
	return this->GetType();
}

//
// FSDataSource
//

FSDataSource::FSDataSource()
{
	_items = ref new Vector<FSDataItem^>();

	StorageFolder^ picturesFolder = KnownFolders::PicturesLibrary;

	IAsyncOperation<IVectorView<IStorageItem^>^>^ fsItemsAsync = picturesFolder->GetItemsAsync();
	IVectorView<IStorageItem^>^ fsItemsVec = fsItemsAsync->GetResults();

	for (int i = 0; i < fsItemsVec->Size; i++)
	{
		IStorageItem^ currentItem = fsItemsVec->GetAt(i);
		IAsyncOperation<BasicProperties^>^ basicPropsAsync = currentItem->GetBasicPropertiesAsync();
		BasicProperties^ basicProps = basicPropsAsync->GetResults();
		FSDataItem^ item = ref new FSDataItem(i.ToString(), currentItem->Name, basicProps->Size.ToString());
		Items->Append(item);
	}

}

IObservableVector<FSDataItem^>^ FSDataSource::Items::get()
{
	return _items;
}

FSDataSource^ FSDataSource::_fsDataSource = nullptr;

task<void> FSDataSource::Init()
{
	if (_fsDataSource == nullptr)
	{
		_fsDataSource = ref new FSDataSource();
	}
	return create_task(_fsDataSource->_loadCompletionEvent);
}

task<FSDataItem^> FSDataSource::GetItem(String^ uniqueId)
{
	return Init()
		.then([uniqueId]() -> FSDataItem ^
	{
		for (const auto& item : _fsDataSource->Items)
		{
			if (item->UniqueId == uniqueId)
			{
				return item;
			}
		}
		return nullptr;
	});
}
