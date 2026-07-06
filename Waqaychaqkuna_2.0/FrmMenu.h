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
#include "EscenarioBiblioteca.h"

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
			escena = new EscenarioBiblioteca();
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
	private: System::Windows::Forms::Label^ lblName;


	private: System::Windows::Forms::ListBox^ lstHistorial;
	private: System::Windows::Forms::Label^ lblPuntajes;
	private: System::Windows::Forms::Button^ btnEliminar;
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
		EscenarioBiblioteca* escena;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lstHistorial = (gcnew System::Windows::Forms::ListBox());
			this->lblPuntajes = (gcnew System::Windows::Forms::Label());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugar.BackgroundImage")));
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(491, 393);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(363, 73);
			this->btnJugar->TabIndex = 1;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenu::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstrucciones.BackgroundImage")));
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(491, 472);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(363, 73);
			this->btnInstrucciones->TabIndex = 2;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.BackgroundImage")));
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(491, 551);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(363, 73);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmMenu::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalir.BackgroundImage")));
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(491, 630);
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
			this->txtName->Location = System::Drawing::Point(491, 356);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(363, 31);
			this->txtName->TabIndex = 5;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblName.Image")));
			this->lblName->Location = System::Drawing::Point(488, 322);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(367, 31);
			this->lblName->TabIndex = 6;
			this->lblName->Text = L"INTRODUCE TU NOMBRE";
			// 
			// lstHistorial
			// 
			this->lstHistorial->BackColor = System::Drawing::Color::LavenderBlush;
			this->lstHistorial->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstHistorial->ItemHeight = 25;
			this->lstHistorial->Location = System::Drawing::Point(885, 375);
			this->lstHistorial->Name = L"lstHistorial";
			this->lstHistorial->Size = System::Drawing::Size(444, 104);
			this->lstHistorial->TabIndex = 0;
			// 
			// lblPuntajes
			// 
			this->lblPuntajes->AutoSize = true;
			this->lblPuntajes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntajes->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblPuntajes.Image")));
			this->lblPuntajes->Location = System::Drawing::Point(1017, 341);
			this->lblPuntajes->Name = L"lblPuntajes";
			this->lblPuntajes->Size = System::Drawing::Size(165, 31);
			this->lblPuntajes->TabIndex = 7;
			this->lblPuntajes->Text = L"PUNTAJES";
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEliminar.BackgroundImage")));
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->Location = System::Drawing::Point(12, 12);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(217, 46);
			this->btnEliminar->TabIndex = 8;
			this->btnEliminar->Text = L"Eliminar Puntaje";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FrmMenu::btnEliminar_Click);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->lblPuntajes);
			this->Controls->Add(this->lstHistorial);
			this->Controls->Add(this->lblName);
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
			FrmSlod1^ slods1 = gcnew FrmSlod1();
			if (slods1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				delete slods1;
				return;
			}
			delete slods1;
			FrmNivel1^ f1 = gcnew FrmNivel1();
			if (f1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				puntaje1 = f1->RetornarPuntaje();
			
				delete f1;
				return;
			}
			puntaje1 = f1->RetornarPuntaje();
			
			delete f1;
			
			FrmSlod2^ slods2 = gcnew FrmSlod2();
			if (slods2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				delete slods2;
				return;
			}
			delete slods2;
			
			FrmNivel2^ f2 = gcnew FrmNivel2();
			if (f2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				puntaje2 = f2->RetornarPuntaje();
			
				delete f2;
				return;
			}
			puntaje2 = f2->RetornarPuntaje();
			delete f2;
			
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
				puntaje3 = f3->RetornarPuntaje();
				delete f3;
				CargarHistorial();
				return;
			}
			puntaje3 = f3->RetornarPuntaje();
			delete f3;

			FrmSlodVictoria^ slodVictoria = gcnew FrmSlodVictoria();
			slodVictoria->ShowDialog();
			delete slodVictoria;

			CargarHistorial();
		}
		Void FrmMenu_Resize(System::Object^ sender, System::EventArgs^ e)
		{
			int centroX = this->ClientSize.Width / 2  - 200;

			int buttonWidth = btnJugar->Width;
			int buttonHeight = btnJugar->Height;
			lblName->Left = centroX - lblName->Width / 2;
			lblName->Top = (this->ClientSize.Height / 2) - 75; 

			lstHistorial->Left = lblName->Right + 20; 
			lblPuntajes->Left = centroX + (buttonWidth / 2) + 40; 
			lblPuntajes->Top = lblName->Top;                     

			lstHistorial->Top = lblPuntajes->Bottom + 8;         
			lblPuntajes->Left = lstHistorial->Left + (lstHistorial->Width / 2) - (lblPuntajes->Width / 2);

			txtName->Left = centroX - buttonWidth / 2;
			txtName->Top = lblName->Bottom + 8;
			// BOTÓN 1
			btnJugar->Left = centroX - buttonWidth / 2;
			btnJugar->Top = this->ClientSize.Height / 2 ;

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
			frm->ShowDialog();
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

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(txtName->Text);
		std::string nombreNativo(static_cast<const char*>(ptr.ToPointer()));
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);

		escena->eliminarPuntaje(nombreNativo);
	}
};
}
