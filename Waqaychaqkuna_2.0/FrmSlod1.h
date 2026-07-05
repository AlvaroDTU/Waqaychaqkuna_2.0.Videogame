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
	private: System::Windows::Forms::Label^ label1;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(1163, 749);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(425, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Presiona ENTER para continuar...";
			// 
			// FrmSlod1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"FrmSlod1";
			this->Text = L"FrmSlod1";
			this->Load += gcnew System::EventHandler(this, &FrmSlod1::FrmSlod1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmSlod1::FrmSlod1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmSlod1_Load(System::Object^ sender, System::EventArgs^ e) {}
	Void FrmSlod1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}
	};
}
