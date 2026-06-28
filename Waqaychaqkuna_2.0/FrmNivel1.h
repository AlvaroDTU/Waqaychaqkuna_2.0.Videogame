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
	private: System::Windows::Forms::Panel^ pnlMapa;

		   BufferedGraphics^ buffer;
	private: System::Windows::Forms::Label^ lblPrueba;
	private: System::Windows::Forms::Label^ lblPista;
	private: System::Windows::Forms::Label^ lblDerrotados;
	private: System::Windows::Forms::Label^ lblPrueba2;
	private: System::Windows::Forms::Label^ lblIntentos;
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
			   this->pnlMapa = (gcnew System::Windows::Forms::Panel());
			   this->lblPrueba = (gcnew System::Windows::Forms::Label());
			   this->lblPista = (gcnew System::Windows::Forms::Label());
			   this->lblDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblPrueba2 = (gcnew System::Windows::Forms::Label());
			   this->lblIntentos = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // tmrNivel1
			   // 
			   this->tmrNivel1->Interval = 16;
			   this->tmrNivel1->Tick += gcnew System::EventHandler(this, &FrmNivel1::tmrNivel1_Tick);
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
			   // lblPrueba
			   // 
			   this->lblPrueba->AutoSize = true;
			   this->lblPrueba->Location = System::Drawing::Point(1319, 317);
			   this->lblPrueba->Name = L"lblPrueba";
			   this->lblPrueba->Size = System::Drawing::Size(13, 13);
			   this->lblPrueba->TabIndex = 1;
			   this->lblPrueba->Text = L"0";
			   // 
			   // lblPista
			   // 
			   this->lblPista->AutoSize = true;
			   this->lblPista->Location = System::Drawing::Point(1319, 270);
			   this->lblPista->Name = L"lblPista";
			   this->lblPista->Size = System::Drawing::Size(132, 13);
			   this->lblPista->TabIndex = 2;
			   this->lblPista->Text = L"PISTA DE REPORTERA: ";
			   // 
			   // lblDerrotados
			   // 
			   this->lblDerrotados->AutoSize = true;
			   this->lblDerrotados->Location = System::Drawing::Point(1319, 402);
			   this->lblDerrotados->Name = L"lblDerrotados";
			   this->lblDerrotados->Size = System::Drawing::Size(155, 13);
			   this->lblDerrotados->TabIndex = 3;
			   this->lblDerrotados->Text = L"ENEMIGOS DERROTADOS: 0";
			   // 
			   // lblPrueba2
			   // 
			   this->lblPrueba2->AutoSize = true;
			   this->lblPrueba2->Location = System::Drawing::Point(1319, 363);
			   this->lblPrueba2->Name = L"lblPrueba2";
			   this->lblPrueba2->Size = System::Drawing::Size(13, 13);
			   this->lblPrueba2->TabIndex = 4;
			   this->lblPrueba2->Text = L"0";
			   // 
			   // lblIntentos
			   // 
			   this->lblIntentos->AutoSize = true;
			   this->lblIntentos->Location = System::Drawing::Point(1319, 448);
			   this->lblIntentos->Name = L"lblIntentos";
			   this->lblIntentos->Size = System::Drawing::Size(74, 13);
			   this->lblIntentos->TabIndex = 5;
			   this->lblIntentos->Text = L"INTENTOS: 0";
			   // 
			   // FrmNivel1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1600, 800);
			   this->Controls->Add(this->lblIntentos);
			   this->Controls->Add(this->lblPrueba2);
			   this->Controls->Add(this->lblDerrotados);
			   this->Controls->Add(this->lblPista);
			   this->Controls->Add(this->lblPrueba);
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
			if (e->KeyCode == Keys::Up) {
				g->setVelocidad(0, -5);
			}
			else if (e->KeyCode == Keys::Down) {
				g->setVelocidad(0, 5);
			}
			else if (e->KeyCode == Keys::Right) {
				g->setVelocidad(5, 0);
			}
			else if (e->KeyCode == Keys::Left) {
				g->setVelocidad(-5, 0);
			}
			else if (e->KeyCode == Keys::E) {
				g->setAccion(true);
				g->setTipoAccion(1);
				// interaccion mostrar info de bienes
			}
			else if (e->KeyCode == Keys::Space) {
				g->setAccion(true);
				g->setTipoAccion(2);
				// descubrir a los ladrones
			}
		}
		Void tmrNivel1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			gestor->jugar();
			this->lblPista->Text = String::Format(L"PISTA DE REPORTERA: {0}", gestor->getReportera()->getTipoPista());
			this->lblPrueba->Text = String::Format(L"ACCION GUARDIA: {0}", gestor->getGuardia()->getAccion());
			this->lblPrueba2->Text = String::Format(L"TIPO ACCION GUARDIA: {0}", gestor->getGuardia()->getTipoAccion());
			this->lblDerrotados->Text = String::Format(L"ENEMIGOS CAPTURADOS: {0}", gestor->getCapturados());
			this->lblIntentos->Text = String::Format(L"INICIADO: {0}", gestor->getIniciado());
			Pintar();
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
