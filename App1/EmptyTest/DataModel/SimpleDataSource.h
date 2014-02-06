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

namespace EmptyTest
{
	namespace Data
	{
		/// <summary>
		/// Generic item data model.
		/// </summary>
		[Windows::UI::Xaml::Data::Bindable]
		public ref class SimpleItem sealed : public Windows::UI::Xaml::Data::ICustomPropertyProvider
		{
		public:
			property Platform::String^ UniqueId { Platform::String^ get(); }
			property Platform::String^ Title { Platform::String^ get(); }

			// Implementation of ICustomPropertyProvider provides a string representation for the object to be used as automation name for accessibility
			virtual Windows::UI::Xaml::Data::ICustomProperty^ GetCustomProperty(Platform::String^ name);
			virtual Windows::UI::Xaml::Data::ICustomProperty^ GetIndexedProperty(Platform::String^ name, Windows::UI::Xaml::Interop::TypeName type);
			virtual Platform::String^ GetStringRepresentation();

			property Windows::UI::Xaml::Interop::TypeName Type { virtual Windows::UI::Xaml::Interop::TypeName get(); }

		internal:
			SimpleItem(Platform::String^ uniqueId, Platform::String^ title);

		private:
			Platform::String^ _uniqueId;
			Platform::String^ _title;
		};

		/// <summary>
		/// Creates a collection of items with content read from a static json file.
		/// </summary>
		[Windows::UI::Xaml::Data::Bindable]
		public ref class SimpleDataSource sealed
		{
		public:
			property Windows::Foundation::Collections::IObservableVector<SimpleItem^>^ Items
			{
				Windows::Foundation::Collections::IObservableVector<SimpleItem^>^ get();
			}

		internal:
			SimpleDataSource();
			static concurrency::task<SimpleItem^> GetItem(Platform::String^ uniqueId);

		private:
			concurrency::task_completion_event<void> _loadCompletionEvent;
			Platform::Collections::Vector<SimpleItem^>^ _items;
			static concurrency::task<void> Init();

			static SimpleDataSource^ _simpleDataSource;
		};
	}
}
