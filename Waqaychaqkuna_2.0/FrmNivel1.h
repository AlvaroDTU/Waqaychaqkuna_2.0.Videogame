#pragma once
#include "Guardia.h"
#include "GestorMuseo.h"

namespace Waqaychaqkuna20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Summary for FrmNivel1
	/// </summary>
	public ref class FrmNivel1 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel1(void)
		{
			InitializeComponent();
			this->KeyPreview = true;
			gestor = new GestorMuseo(16);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmNivel1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Timer^ tmrNivel1;


		   BufferedGraphics^ buffer;
	private: System::Windows::Forms::Label^ lblArtilugio1;

	private: System::Windows::Forms::Label^ lblPista;
	private: System::Windows::Forms::Label^ lblDerrotados;
	private: System::Windows::Forms::Label^ lblArtilugio2;

	private: System::Windows::Forms::Label^ lblIntentos;
	private: System::Windows::Forms::Label^ lblArtilugio3;
	private: System::Windows::Forms::Label^ lblArtilugio6;
	private: System::Windows::Forms::Label^ lblArtilugio5;
	private: System::Windows::Forms::Label^ lblArtilugio4;
	private: System::Windows::Forms::Label^ lblInstruccion;

	private: System::Windows::Forms::Panel^ pnlMapa;
		   GestorMuseo* gestor;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->tmrNivel1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblArtilugio1 = (gcnew System::Windows::Forms::Label());
			   this->lblPista = (gcnew System::Windows::Forms::Label());
			   this->lblDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio2 = (gcnew System::Windows::Forms::Label());
			   this->lblIntentos = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio3 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio6 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio5 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio4 = (gcnew System::Windows::Forms::Label());
			   this->lblInstruccion = (gcnew System::Windows::Forms::Label());
			   this->pnlMapa = (gcnew System::Windows::Forms::Panel());
			   this->SuspendLayout();
			   // 
			   // tmrNivel1
			   // 
			   this->tmrNivel1->Interval = 16;
			   this->tmrNivel1->Tick += gcnew System::EventHandler(this, &FrmNivel1::tmrNivel1_Tick);
			   // 
			   // lblArtilugio1
			   // 
			   this->lblArtilugio1->AutoSize = true;
			   this->lblArtilugio1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio1->Location = System::Drawing::Point(1319, 304);
			   this->lblArtilugio1->Name = L"lblArtilugio1";
			   this->lblArtilugio1->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio1->TabIndex = 1;
			   this->lblArtilugio1->Text = L"ARTILUGIO 1:";
			   // 
			   // lblPista
			   // 
			   this->lblPista->AutoSize = true;
			   this->lblPista->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblPista->Location = System::Drawing::Point(1319, 741);
			   this->lblPista->Name = L"lblPista";
			   this->lblPista->Size = System::Drawing::Size(107, 17);
			   this->lblPista->TabIndex = 2;
			   this->lblPista->Text = L"PEDIR PISTA!";
			   this->lblPista->Visible = false;
			   // 
			   // lblDerrotados
			   // 
			   this->lblDerrotados->AutoSize = true;
			   this->lblDerrotados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblDerrotados->Location = System::Drawing::Point(1319, 648);
			   this->lblDerrotados->Name = L"lblDerrotados";
			   this->lblDerrotados->Size = System::Drawing::Size(221, 17);
			   this->lblDerrotados->TabIndex = 3;
			   this->lblDerrotados->Text = L"ENEMIGOS DERROTADOS: 0";
			   // 
			   // lblArtilugio2
			   // 
			   this->lblArtilugio2->AutoSize = true;
			   this->lblArtilugio2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio2->Location = System::Drawing::Point(1319, 367);
			   this->lblArtilugio2->Name = L"lblArtilugio2";
			   this->lblArtilugio2->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio2->TabIndex = 4;
			   this->lblArtilugio2->Text = L"ARTILUGIO 2:";
			   // 
			   // lblIntentos
			   // 
			   this->lblIntentos->AutoSize = true;
			   this->lblIntentos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblIntentos->Location = System::Drawing::Point(1319, 694);
			   this->lblIntentos->Name = L"lblIntentos";
			   this->lblIntentos->Size = System::Drawing::Size(105, 17);
			   this->lblIntentos->TabIndex = 5;
			   this->lblIntentos->Text = L"INTENTOS: 0";
			   // 
			   // lblArtilugio3
			   // 
			   this->lblArtilugio3->AutoSize = true;
			   this->lblArtilugio3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio3->Location = System::Drawing::Point(1319, 430);
			   this->lblArtilugio3->Name = L"lblArtilugio3";
			   this->lblArtilugio3->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio3->TabIndex = 6;
			   this->lblArtilugio3->Text = L"ARTILUGIO 3:";
			   // 
			   // lblArtilugio6
			   // 
			   this->lblArtilugio6->AutoSize = true;
			   this->lblArtilugio6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio6->Location = System::Drawing::Point(1455, 430);
			   this->lblArtilugio6->Name = L"lblArtilugio6";
			   this->lblArtilugio6->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio6->TabIndex = 9;
			   this->lblArtilugio6->Text = L"ARTILUGIO 6:";
			   // 
			   // lblArtilugio5
			   // 
			   this->lblArtilugio5->AutoSize = true;
			   this->lblArtilugio5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio5->Location = System::Drawing::Point(1455, 367);
			   this->lblArtilugio5->Name = L"lblArtilugio5";
			   this->lblArtilugio5->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio5->TabIndex = 8;
			   this->lblArtilugio5->Text = L"ARTILUGIO 5:";
			   // 
			   // lblArtilugio4
			   // 
			   this->lblArtilugio4->AutoSize = true;
			   this->lblArtilugio4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio4->Location = System::Drawing::Point(1455, 304);
			   this->lblArtilugio4->Name = L"lblArtilugio4";
			   this->lblArtilugio4->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio4->TabIndex = 7;
			   this->lblArtilugio4->Text = L"ARTILUGIO 4:";
			   // 
			   // lblInstruccion
			   // 
			   this->lblInstruccion->AutoSize = true;
			   this->lblInstruccion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblInstruccion->Location = System::Drawing::Point(1344, 161);
			   this->lblInstruccion->Name = L"lblInstruccion";
			   this->lblInstruccion->Size = System::Drawing::Size(207, 40);
			   this->lblInstruccion->TabIndex = 10;
			   this->lblInstruccion->Text = L"   \'E\' PARA  \nCAPTURAR LADRONES";
			   // 
			   // pnlMapa
			   // 
			   this->pnlMapa->BackColor = System::Drawing::Color::White;
			   this->pnlMapa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->pnlMapa->Location = System::Drawing::Point(0, 0);
			   this->pnlMapa->Name = L"pnlMapa";
			   this->pnlMapa->Size = System::Drawing::Size(1300, 800);
			   this->pnlMapa->TabIndex = 0;
			   // 
			   // FrmNivel1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1600, 800);
			   this->Controls->Add(this->lblInstruccion);
			   this->Controls->Add(this->lblArtilugio6);
			   this->Controls->Add(this->lblArtilugio5);
			   this->Controls->Add(this->lblArtilugio4);
			   this->Controls->Add(this->lblArtilugio3);
			   this->Controls->Add(this->lblIntentos);
			   this->Controls->Add(this->lblArtilugio2);
			   this->Controls->Add(this->lblDerrotados);
			   this->Controls->Add(this->lblPista);
			   this->Controls->Add(this->lblArtilugio1);
			   this->Controls->Add(this->pnlMapa);
			   this->Name = L"FrmNivel1";
			   this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->Text = L"Nivel 1: Museo";
			   this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmNivel1_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyUp);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private:
		Void FrmNivel1_Load(System::Object^ sender, System::EventArgs^ e) {

			gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);
			gestor->crearSprites();
			BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
			Graphics^ g = this->pnlMapa->CreateGraphics();
			buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
			tmrNivel1->Start();
			delete g;

		}
		Void FrmNivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			Guardia* g = gestor->getGuardia();
			if (gestor->getDialogo()->estaActivo())
			{
				if (e->KeyCode == Keys::Space || e->KeyCode == Keys::Enter)
					gestor->getDialogo()->avanzar();
				e->Handled = true;
				return;
			}
			if (e->KeyCode == Keys::Up) 
				g->setVelocidad(0, -5);
			else if (e->KeyCode == Keys::Down)
				g->setVelocidad(0, 5);
			else if (e->KeyCode == Keys::Right)
				g->setVelocidad(5, 0);
			else if (e->KeyCode == Keys::Left)
				g->setVelocidad(-5, 0);
			else if (e->KeyCode == Keys::E) {
				g->setAccion(true);
				g->setTipoAccion(1);
				// interaccion descubrir a los ladrones
			}
			else if (e->KeyCode == Keys::D) {
				g->setAccion(true);
				g->setTipoAccion(2);
				// mostrar descripcion de bienes
			}
		}
		Void tmrNivel1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			gestor->jugar();
			int tPista = gestor->getReportera()->getTipoPista();
			if (tPista < 4) this->lblPista->Visible = true;
			if (tPista == 1) this->lblPista->Text = L"PISTA: BANDANA EN LAS PIERNAS";
			if (tPista == 2) this->lblPista->Text = L"PISTA: BANDANA EN LOS BRAZOS";
			if (tPista == 3) this->lblPista->Text = L"PISTA: CAMISA NEGRA";

			lblArtilugio1->Text = String::Format("Puntaje\nCabeza Clava:\n{0}", gestor->getBien(0)->getPuntajeValor());
			lblArtilugio2->Text = String::Format("Puntaje\nManto Paracas:\n{0}", gestor->getBien(1)->getPuntajeValor());
			lblArtilugio3->Text = String::Format("Puntaje\nCraneo Paracas:\n{0}", gestor->getBien(2)->getPuntajeValor());
			lblArtilugio4->Text = String::Format("Puntaje\nHuaco Moche:\n{0}", gestor->getBien(3)->getPuntajeValor());
			lblArtilugio5->Text = String::Format("Puntaje\nTumi de Oro:\n{0}", gestor->getBien(4)->getPuntajeValor());
			lblArtilugio6->Text = String::Format("Puntaje\nVaso Kero:\n{0}", gestor->getBien(5)->getPuntajeValor());
			this->lblDerrotados->Text = String::Format(L"ENEMIGOS CAPTURADOS: {0}", gestor->getCapturados());
			this->lblIntentos->Text = String::Format(L"INTENTOS: {0}", gestor->getIntentos());

			Pintar();

			if (gestor->victoria())
			{
				this->tmrNivel1->Stop();
				MessageBox::Show("GANASTE");
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			if (gestor->derrota())
			{
				this->tmrNivel1->Stop();
				MessageBox::Show("PERDISTE");
				this->Close();
			}
		}
		Void Pintar()
		{
			gestor->dibujar(buffer->Graphics);
			Graphics^ g = this->pnlMapa->CreateGraphics();
			buffer->Render(g);
			delete g;
		}
		Void FrmNivel1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
		{
			Guardia* g = gestor->getGuardia();
			g->setVelocidad(0, 0);
			g->setAccion(false);
			g->setTipoAccion(0);
		}
};
}
