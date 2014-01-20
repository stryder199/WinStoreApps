//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace FileExplorer
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::UI::Xaml::Data::Bindable]
	public ref class MainPage sealed
	{
	public:
		MainPage();

		/// <summary>
		/// This can be changed to a strongly typed view model.
		/// </summary>
		property Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^ DefaultViewModel
		{
			Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^  get();
		}

	private:
		void MainPage::LoadState(Object^ sender, Common::LoadStateEventArgs^ e);

		static Windows::UI::Xaml::DependencyProperty^ _defaultViewModelProperty;
	};
}
