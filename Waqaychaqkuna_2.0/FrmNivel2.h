#pragma once
#include "GestorHuacas.h"
namespace Waqaychaqkuna20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmNivel2
	/// </summary>
	public ref class FrmNivel2 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel2(void)
		{
			InitializeComponent();
			this->KeyPreview = true;
			gestor = new GestorHuacas(10);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmNivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlMapa;
	private: System::Windows::Forms::Timer^ tmrJuego;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ lblPrueba;
	private: System::Windows::Forms::Label^ lblPrueba2;
		   GestorHuacas* gestor;
		   BufferedGraphics^ buffer;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlMapa = (gcnew System::Windows::Forms::Panel());
			this->tmrJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblPrueba = (gcnew System::Windows::Forms::Label());
			this->lblPrueba2 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca1 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca2 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca3 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// pnlMapa
			// 
			this->pnlMapa->BackColor = System::Drawing::Color::White;
			this->pnlMapa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pnlMapa->Location = System::Drawing::Point(0, 0);
			this->pnlMapa->Name = L"pnlMapa";
			this->pnlMapa->Size = System::Drawing::Size(1300, 800);
			this->pnlMapa->TabIndex = 1;
			// 
			// tmrJuego
			// 
			this->tmrJuego->Interval = 16;
			this->tmrJuego->Tick += gcnew System::EventHandler(this, &FrmNivel2::tmrJuego_Tick);
			// 
			// lblPrueba
			// 
			this->lblPrueba->AutoSize = true;
			this->lblPrueba->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrueba->Location = System::Drawing::Point(1333, 195);
			this->lblPrueba->Name = L"lblPrueba";
			this->lblPrueba->Size = System::Drawing::Size(81, 19);
			this->lblPrueba->TabIndex = 2;
			this->lblPrueba->Text = L"label1";
			// 
			// lblPrueba2
			// 
			this->lblPrueba2->AutoSize = true;
			this->lblPrueba2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrueba2->Location = System::Drawing::Point(1333, 226);
			this->lblPrueba2->Name = L"lblPrueba2";
			this->lblPrueba2->Size = System::Drawing::Size(81, 19);
			this->lblPrueba2->TabIndex = 3;
			this->lblPrueba2->Text = L"label1";
			// 
			// lblHuaca1
			// 
			this->lblHuaca1->AutoSize = true;
			this->lblHuaca1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca1->Location = System::Drawing::Point(1333, 262);
			this->lblHuaca1->Name = L"lblHuaca1";
			this->lblHuaca1->Size = System::Drawing::Size(81, 19);
			this->lblHuaca1->TabIndex = 4;
			this->lblHuaca1->Text = L"label1";
			// 
			// lblHuaca2
			// 
			this->lblHuaca2->AutoSize = true;
			this->lblHuaca2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca2->Location = System::Drawing::Point(1333, 296);
			this->lblHuaca2->Name = L"lblHuaca2";
			this->lblHuaca2->Size = System::Drawing::Size(81, 19);
			this->lblHuaca2->TabIndex = 5;
			this->lblHuaca2->Text = L"label1";
			// 
			// lblHuaca3
			// 
			this->lblHuaca3->AutoSize = true;
			this->lblHuaca3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca3->Location = System::Drawing::Point(1333, 325);
			this->lblHuaca3->Name = L"lblHuaca3";
			this->lblHuaca3->Size = System::Drawing::Size(81, 19);
			this->lblHuaca3->TabIndex = 6;
			this->lblHuaca3->Text = L"label1";
			// 
			// lblHuaca4
			// 
			this->lblHuaca4->AutoSize = true;
			this->lblHuaca4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca4->Location = System::Drawing::Point(1333, 353);
			this->lblHuaca4->Name = L"lblHuaca4";
			this->lblHuaca4->Size = System::Drawing::Size(81, 19);
			this->lblHuaca4->TabIndex = 7;
			this->lblHuaca4->Text = L"label1";
			// 
			// FrmNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->lblHuaca4);
			this->Controls->Add(this->lblHuaca3);
			this->Controls->Add(this->lblHuaca2);
			this->Controls->Add(this->lblHuaca1);
			this->Controls->Add(this->lblPrueba2);
			this->Controls->Add(this->lblPrueba);
			this->Controls->Add(this->pnlMapa);
			this->Name = L"FrmNivel2";
			this->Text = L"FrmNivel2";
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmNivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmNivel2_Load(System::Object^ sender, System::EventArgs^ e) {
		gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);
		gestor->crearSprites();

		BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
		Graphics^ g = this->pnlMapa->CreateGraphics();
		buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
		tmrJuego->Start();
		delete g;
	}
	private: System::Void FrmNivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
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
			gestor->generarCuidador();
		}
		
	}

	 Void Pintar()
	 {
	  gestor->dibujar(buffer->Graphics);
	
	  Graphics^ g = this->pnlMapa->CreateGraphics();
	  buffer->Render(g);
	  delete g;
	 }
	private: System::Void FrmNivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Guardia* g = gestor->getGuardia();
		g->setVelocidad(0, 0);
	}
private: System::Void tmrJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
	lblPrueba->Text = String::Format("PosX: {0}", gestor->getGuardia()->getPosX());
	lblPrueba2->Text = String::Format("PosY: {0}", gestor->getGuardia()->getPosY());
	lblHuaca1->Text = String::Format("Puntaje: {0}", gestor->getBien(0)->getPuntajeValor());
	lblHuaca2->Text = String::Format("Puntaje: {0}", gestor->getBien(1)->getPuntajeValor());
	lblHuaca3->Text = String::Format("Puntaje: {0}", gestor->getBien(2)->getPuntajeValor());
	lblHuaca4->Text = String::Format("Puntaje: {0}", gestor->getBien(3)->getPuntajeValor());
	gestor->detectarColisiones();
	gestor->jugar();
	Pintar();
}
};
}
