//
// SampleDataSource.cpp
// Implementation of the SampleDataSource, SampleDataGroup, SampleDataItem, and SampleDataCommon classes
//

#include "pch.h"
#include <stdlib.h>
#include <string>

using namespace EmptyTest::Data;

using namespace Platform;
using namespace Platform::Collections;
using namespace concurrency;
using namespace std;
using namespace Windows::ApplicationModel::Resources::Core;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
using namespace Windows::Storage::FileProperties;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;

//
// FSDataItem
//

SimpleItem::SimpleItem(String^ uniqueId, String^ title) :
	_uniqueId(uniqueId),
	_title(title)
{
}

String^ SimpleItem::UniqueId::get()
{
	return _uniqueId;
}

String^ SimpleItem::Title::get()
{
	return _title;
}

Windows::UI::Xaml::Data::ICustomProperty^ SimpleItem::GetCustomProperty(Platform::String^ name)
{
	return nullptr;
}

Windows::UI::Xaml::Data::ICustomProperty^ SimpleItem::GetIndexedProperty(Platform::String^ name, Windows::UI::Xaml::Interop::TypeName type)
{
	return nullptr;
}

Platform::String^ SimpleItem::GetStringRepresentation()
{
	return Title;
}

Windows::UI::Xaml::Interop::TypeName SimpleItem::Type::get()
{
	return this->GetType();
}

//
// FSDataSource
//

SimpleDataSource::SimpleDataSource()
{
	_items = ref new Vector<SimpleItem^>();
	
	StorageFolder^ picturesFolder = KnownFolders::PicturesLibrary;

	create_task(picturesFolder->GetFilesAsync())
		.then([this](IVectorView<StorageFile^>^ fsFileVec)
	{
		for (int i = 0; i < fsFileVec->Size; i++)
		{
			IStorageItem^ currentItem = fsFileVec->GetAt(i);
			auto fileSize = make_shared<wstring>();

			create_task(currentItem->GetBasicPropertiesAsync())
				.then([fileSize](BasicProperties^ basicProp)
			{
				*fileSize += std::to_wstring(basicProp->Size);
			})
				.then([fileSize, this, i, currentItem]()
			{
				SimpleItem^ item = ref new SimpleItem(i.ToString(), currentItem->Name);
				Items->Append(item);
			});
		}
	});
}

IObservableVector<SimpleItem^>^ SimpleDataSource::Items::get()
{
	return _items;
}

SimpleDataSource^ SimpleDataSource::_simpleDataSource = nullptr;

task<void> SimpleDataSource::Init()
{
	if (_simpleDataSource == nullptr)
	{
		_simpleDataSource = ref new SimpleDataSource();
	}
	return create_task(_simpleDataSource->_loadCompletionEvent);
}

task<SimpleItem^> SimpleDataSource::GetItem(String^ uniqueId)
{
	return Init()
		.then([uniqueId]() -> SimpleItem ^
	{
		for (const auto& item : _simpleDataSource->Items)
		{
			if (item->UniqueId == uniqueId)
			{
				return item;
			}
		}
		return nullptr;
	});
}
