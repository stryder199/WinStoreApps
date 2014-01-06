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
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};

	/*public ref class FileSystemItem
	{
	public:

	private:
		std::string name, path;
	};

	public ref class File : public FileSystemItem
	{
	public:

	private:
		std::string thumbnail;
	};

	public ref class Folder : public FileSystemItem
	{
	public:

	private:
	};*/
}
