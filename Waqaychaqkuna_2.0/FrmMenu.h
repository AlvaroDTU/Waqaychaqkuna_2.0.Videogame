#pragma once
#include "FrmNivel1.h"
#include "FrmNivel2.h"
#include "FrmNivel3.h"

namespace Waqaychaqkuna20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMenu
	/// </summary>
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
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
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnJugar;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(658, 374);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(300, 90);
			this->btnJugar->TabIndex = 1;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenu::btnJugar_Click);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->btnJugar);
			this->Name = L"FrmMenu";
			this->Text = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {}
	Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		FrmNivel1^ f1 = gcnew FrmNivel1();
		if (f1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			delete f1;
			return;
		}
		delete f1;

			FrmNivel2^ f2 = gcnew FrmNivel2();
		if (f2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			delete f2;
			return;
		}
		delete f2;

		              FrmNivel3^ f3 = gcnew FrmNivel3();
		              if (f3->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		              {
		              	delete f3;
		              	return;
		              }
		              delete f3;
	}
	};
}
	