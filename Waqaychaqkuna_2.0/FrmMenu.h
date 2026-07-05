#pragma once
#include "FrmNivel1.h"
#include "FrmNivel2.h"
#include "FrmNivel3.h"
#include "FrmSlod1.h"
#include "FrmSlod2.h"
#include "FrmSlod3.h"
#include "FrmSlodVictoria.h"
#include "FrmInstrucciones.h"
#include "FrmCreditos.h"
#include "GestorBiblioteca.h"

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
			escena = new GestorBiblioteca();
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
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ lstHistorial;
	private: System::Windows::Forms::Button^ btnSalir;
	protected: virtual void OnPaint(PaintEventArgs^ e) override
	{
		Graphics^ g = e->Graphics;
		g->DrawImage(gcnew Bitmap("backgrounds\\Menu.png"), this->ClientRectangle);
		Form::OnPaint(e);
	}
	private:
		int puntaje1=0;
		int puntaje2=0;
		int puntaje3=0;
		int puntajeTotal=0;
		GestorBiblioteca* escena;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lstHistorial = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(636, 393);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(363, 73);
			this->btnJugar->TabIndex = 1;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenu::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(636, 474);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(363, 73);
			this->btnInstrucciones->TabIndex = 2;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(636, 554);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(363, 73);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmMenu::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(636, 637);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(363, 65);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenu::btnSalir_Click);
			// 
			// txtName
			// 
			this->txtName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtName->Location = System::Drawing::Point(636, 356);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(363, 31);
			this->txtName->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(634, 322);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(367, 31);
			this->label1->TabIndex = 6;
			this->label1->Text = L"INTRODUCE TU NOMBRE";
			// 
			// lstHistorial
			// 
			this->lstHistorial->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
			this->lstHistorial->ItemHeight = 15;
			this->lstHistorial->Location = System::Drawing::Point(30, 202);
			this->lstHistorial->Name = L"lstHistorial";
			this->lstHistorial->Size = System::Drawing::Size(320, 124);
			this->lstHistorial->TabIndex = 0;
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->lstHistorial);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Name = L"FrmMenu";
			this->Text = L"Waqaychaqkuna";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->Resize += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
			CargarHistorial();
		}
		Void CargarHistorial()
        {
            vector<Puntaje*> puntajes = escena->historial();
            int n = (int)puntajes.size();

       
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - 1 - i; j++)
                    if (puntajes[j]->getFecha() < puntajes[j + 1]->getFecha())
                    {
                        Puntaje* temp = puntajes[j];
                        puntajes[j] = puntajes[j + 1];
                        puntajes[j + 1] = temp;
                    }

            lstHistorial->Items->Clear();
			for (int i = 0; i < n; i++)
			{
				System::String^ nombre = gcnew System::String(puntajes[i]->getNombre().c_str());
				System::String^ fecha = gcnew System::String(puntajes[i]->getFecha().c_str());

				lstHistorial->Items->Add(
					System::String::Format("{0}  -  {1,5} pts  -  {2}",
						nombre,
						puntajes[i]->getPuntos(),
						fecha));
			}

            for (int i = 0; i < n; i++)
                delete puntajes[i];

        }
		Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//FrmSlod1^ slods1 = gcnew FrmSlod1();
			//if (slods1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			//{
			//	delete slods1;
			//	return;
			//}
			//delete slods1;
			FrmNivel1^ f1 = gcnew FrmNivel1();
			if (f1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				puntaje1 = f1->RetornarPuntaje();
			
				delete f1;
				return;
			}
			puntaje1 = f1->RetornarPuntaje();
			
			delete f1;
			//
			//FrmSlod2^ slods2 = gcnew FrmSlod2();
			//if (slods2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			//{
			//	delete slods2;
			//	return;
			//}
			//delete slods2;
			//
			//FrmNivel2^ f2 = gcnew FrmNivel2();
			//if (f2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			//{
			//	puntaje2 = f2->RetornarPuntaje();
			//
			//	delete f2;
			//	return;
			//}
			//puntaje2 = f2->RetornarPuntaje();
			//delete f2;
			
			puntajeTotal = puntaje1 + puntaje2;
			
			FrmSlod3^ slods3 = gcnew FrmSlod3();
			if (slods3->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				delete slods3;
				return;
			}
			delete slods3;
			FrmNivel3^ f3 = gcnew FrmNivel3(puntajeTotal, txtName->Text);
			if (f3->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				//puntaje3 = f3->RetornarPuntaje();
				delete f3;

				// FrmSlodVictoria^ slodVictoria = gcnew FrmSlodVictoria();
				// slodVictoria->ShowDialog();
				return;
			}
			//puntaje3 = f3->RetornarPuntaje();
			delete f3;


		}
		Void FrmMenu_Resize(System::Object^ sender, System::EventArgs^ e)
		{
			int centroX = this->ClientSize.Width / 2;

			int buttonWidth = btnJugar->Width;
			int buttonHeight = btnJugar->Height;

			// BOTÓN 1
			btnJugar->Left = centroX - buttonWidth / 2;
			btnJugar->Top = this->ClientSize.Height / 2 - 100;

			// BOTÓN 2
			btnInstrucciones->Left = centroX - buttonWidth / 2;
			btnInstrucciones->Top = btnJugar->Bottom + 15;

			// BOTÓN 3
			btnCreditos->Left = centroX - buttonWidth / 2;
			btnCreditos->Top = btnInstrucciones->Bottom + 15;

			// BOTÓN 4
			btnSalir->Left = centroX - buttonWidth / 2;
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
			FrmCreditos^ frm = gcnew FrmCreditos();
			frm->ShowDialog();
			delete frm;
		}
		Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

	};
}
