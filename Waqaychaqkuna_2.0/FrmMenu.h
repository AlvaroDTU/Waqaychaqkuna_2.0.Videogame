#pragma once
#include "FrmNivel1.h"
#include "FrmNivel2.h"
#include "FrmNivel3.h"
#include "FrmInstrucciones.h"

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
			this->SetStyle(ControlStyles::AllPaintingInWmPaint |
				ControlStyles::UserPaint |
				ControlStyles::DoubleBuffer, true);
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
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnSalir;
    protected: virtual void OnPaint(PaintEventArgs^ e) override
		   {
			   Graphics^ g = e->Graphics;
			   g->DrawImage(gcnew Bitmap("backgrounds\\Menu.png"),this->ClientRectangle);
			   Form::OnPaint(e);
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
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(575, 295);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(450, 90);
			this->btnJugar->TabIndex = 1;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenu::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(575, 400);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(450, 90);
			this->btnInstrucciones->TabIndex = 2;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(575, 505);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(450, 90);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmMenu::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(575, 610);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(450, 90);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenu::btnSalir_Click);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Name = L"FrmMenu";
			this->Text = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->Resize += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion

	Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {}
	Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//FrmNivel1^ f1 = gcnew FrmNivel1();
		//if (f1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		//{
		//	delete f1;
		//	return;
		//}
		//delete f1;
		
		FrmNivel2^ f2 = gcnew FrmNivel2();
		if (f2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			delete f1;
			return;
		}
		delete f1;
		
		//FrmNivel2^ f2 = gcnew FrmNivel2();
		//if (f2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		//{
		//	delete f2;
		//	return;
		//}
		//delete f2;
		 
		FrmNivel3^ f3 = gcnew FrmNivel3();
		if (f3->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			delete f3;
			return;
		}
		delete f3;
	}
	Void FrmMenu_Resize(System::Object^ sender, System::EventArgs^ e) 
	{
		int centerX = this->ClientSize.Width / 2;

		int buttonWidth = btnJugar->Width;
		int buttonHeight = btnJugar->Height;

		// BOTÓN 1
		btnJugar->Left = centerX - buttonWidth / 2;
		btnJugar->Top = this->ClientSize.Height / 2 - 100;

		// BOTÓN 2
		btnInstrucciones->Left = centerX - buttonWidth / 2;
		btnInstrucciones->Top = btnJugar->Bottom + 15;

		// BOTÓN 3
		btnCreditos->Left = centerX - buttonWidth / 2;
		btnCreditos->Top = btnInstrucciones->Bottom + 15;

		// BOTÓN 4
		btnSalir->Left = centerX - buttonWidth / 2;
		btnSalir->Top = btnCreditos->Bottom + 15;

		this->Invalidate();
	}
	Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		FrmInstrucciones^ frm = gcnew FrmInstrucciones();
		delete frm;
	}
	Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//
	}
	Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	
};
}
	