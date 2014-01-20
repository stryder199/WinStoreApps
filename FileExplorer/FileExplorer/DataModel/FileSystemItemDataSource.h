//
// FSDataSource.h
// Declaration of the FSDataSource and FSDataItem classes
//

#pragma once

// The data model defined by this file serves as a representative example of a strongly-typed
// model.  The property names chosen coincide with data bindings in the standard item templates.
//
// Applications may use this model as a starting point and build on it, or discard it entirely and
// replace it with something appropriate to their needs. If using this model, you might improve app 
// responsiveness by initiating the data loading task in the code behind for App.xaml when the app 
// is first launched.

namespace FileExplorer
{
	namespace Data
	{
		/// <summary>
		/// Generic item data model.
		/// </summary>
		[Windows::UI::Xaml::Data::Bindable]
		public ref class FSDataItem sealed : public Windows::UI::Xaml::Data::ICustomPropertyProvider
		{
		public:
			property Platform::String^ UniqueId { Platform::String^ get(); }
			property Platform::String^ Filename { Platform::String^ get(); }
			property Platform::String^ FileSize { Platform::String^ get(); }

			// Implementation of ICustomPropertyProvider provides a string representation for the object to be used as automation name for accessibility
			virtual Windows::UI::Xaml::Data::ICustomProperty^ GetCustomProperty(Platform::String^ name);
			virtual Windows::UI::Xaml::Data::ICustomProperty^ GetIndexedProperty(Platform::String^ name, Windows::UI::Xaml::Interop::TypeName type);
			virtual Platform::String^ GetStringRepresentation();

			property Windows::UI::Xaml::Interop::TypeName Type { virtual Windows::UI::Xaml::Interop::TypeName get(); }

		internal:
			FSDataItem(Platform::String^ uniqueId, Platform::String^ title, Platform::String^ subtitle);

		private:
			Platform::String^ _uniqueId;
			Platform::String^ _filename;
			Platform::String^ _filesize;
		};

		/// <summary>
		/// Creates a collection of items with content read from a static json file.
		/// </summary>
		[Windows::UI::Xaml::Data::Bindable]
		public ref class FSDataSource sealed
		{
		public:
			property Windows::Foundation::Collections::IObservableVector<FSDataItem^>^ Items
			{
				Windows::Foundation::Collections::IObservableVector<FSDataItem^>^ get();
			}

		internal:
			FSDataSource();
			static concurrency::task<FSDataItem^> GetItem(Platform::String^ uniqueId);

		private:
			concurrency::task_completion_event<void> _loadCompletionEvent;
			Platform::Collections::Vector<FSDataItem^>^ _items;
			static concurrency::task<void> Init();

			static FSDataSource^ _fsDataSource;
		};
	}
}
