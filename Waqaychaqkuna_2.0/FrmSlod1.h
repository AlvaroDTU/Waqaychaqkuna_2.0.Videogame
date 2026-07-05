#pragma once

namespace Waqaychaqkuna20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmSlod1
	/// </summary>
	public ref class FrmSlod1 : public System::Windows::Forms::Form
	{
	public:
		FrmSlod1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmSlod1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmSlod1::typeid));
			this->SuspendLayout();
			// 
			// FrmSlod1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->DoubleBuffered = true;
			this->Name = L"FrmSlod1";
			this->Text = L"FrmSlod1";
			this->Load += gcnew System::EventHandler(this, &FrmSlod1::FrmSlod1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmSlod1_Load(System::Object^ sender, System::EventArgs^ e) {}
	};
}
