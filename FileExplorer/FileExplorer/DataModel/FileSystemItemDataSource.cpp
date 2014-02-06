//
// SampleDataSource.cpp
// Implementation of the SampleDataSource, SampleDataGroup, SampleDataItem, and SampleDataCommon classes
//

#include "pch.h"
#include <stdlib.h>
#include <string>

using namespace FileExplorer::Data;

using namespace Platform;
using namespace Platform::Collections;
using namespace concurrency;
using namespace std;
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
// FSDataGroup
//

FSDataGroup::FSDataGroup(String^ uniqueId, String^ title) :
_uniqueId(uniqueId),
_title(title),
_items(ref new Vector<FSDataItem^>())
{
}

String^ FSDataGroup::UniqueId::get()
{
	return _uniqueId;
}

String^ FSDataGroup::Title::get()
{
	return _title;
}

Windows::UI::Xaml::Data::ICustomProperty^ FSDataGroup::GetCustomProperty(Platform::String^ name)
{
	return nullptr;
}

Windows::UI::Xaml::Data::ICustomProperty^ FSDataGroup::GetIndexedProperty(Platform::String^ name, Windows::UI::Xaml::Interop::TypeName type)
{
	return nullptr;
}

Platform::String^ FSDataGroup::GetStringRepresentation()
{
	return Title;
}

Windows::UI::Xaml::Interop::TypeName FSDataGroup::Type::get()
{
	return this->GetType();
}

IObservableVector<FSDataItem^>^ FSDataGroup::Items::get()
{
	return _items;
}

//
// FSDataSource
//
 
FSDataSource::FSDataSource() :
  _groups(ref new Vector<FSDataGroup^>())
{
	StorageFolder^ picturesFolder = KnownFolders::PicturesLibrary;

	create_task(picturesFolder->GetFoldersAsync())
		.then([this](IVectorView<StorageFolder^>^ fsFileVec)
	{
		FSDataGroup^ folderGroup = ref new FSDataGroup("0", "Folders");
		Groups->Append(folderGroup);

		for (int i = 0; i < fsFileVec->Size; i++)
		{
			IStorageItem^ currentItem = fsFileVec->GetAt(i);
			FSDataItem^ item = ref new FSDataItem(i.ToString(), currentItem->Name, "");
			folderGroup->Items->Append(item);
		}
	})
		// We need to explicitly state the return type 
		// here: -> IAsyncOperation<...>
		.then([picturesFolder]() -> IAsyncOperation<IVectorView<StorageFile^>^>^
	{
		return picturesFolder->GetFilesAsync();
	})
		.then([this] (IVectorView<StorageFile^>^ fsFileVec)
	{
		FSDataGroup^ filesGroup = ref new FSDataGroup("1", "Files");
		Groups->Append(filesGroup);

		for (int i = 0; i < fsFileVec->Size; i++)
		{
			IStorageItem^ currentItem = fsFileVec->GetAt(i);
			auto fileSize = make_shared<wstring>();
			
			create_task(currentItem->GetBasicPropertiesAsync())
				.then([fileSize](BasicProperties^ basicProp)
			{
				*fileSize += std::to_wstring(basicProp->Size);
			})
				.then([fileSize, this, i , currentItem, filesGroup]()
			{
				FSDataItem^ item = ref new FSDataItem(i.ToString(), currentItem->Name, ref new String((*fileSize).c_str()));
				filesGroup->Items->Append(item);
			});
		}
	});
}

IObservableVector<FSDataGroup^>^ FSDataSource::Groups::get()
{
	return _groups;
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

task<IIterable<FSDataGroup^>^> FSDataSource::GetGroups()
{
	return Init()
		.then([]() -> IIterable<FSDataGroup^> ^
	{
		return _fsDataSource->Groups;
	});
}

task<FSDataGroup^> FSDataSource::GetGroup(String^ uniqueId)
{
	return Init()
		.then([uniqueId]() -> FSDataGroup ^
	{
		// Simple linear search is acceptable for small data sets
		for (const auto& group : _fsDataSource->Groups)
		{
			if (group->UniqueId == uniqueId)
			{
				return group;
			}
		}
		return nullptr;
	});
}

task<FSDataItem^> FSDataSource::GetItem(String^ uniqueId)
{
	return Init()
		.then([uniqueId]() -> FSDataItem ^
	{
		// Simple linear search is acceptable for small data sets
		for (const auto& group : _fsDataSource->Groups)
		{
			for (const auto& item : group->Items)
			{
				if (item->UniqueId == uniqueId)
				{
					return item;
				}
			}
		}
		return nullptr;
	});
}
