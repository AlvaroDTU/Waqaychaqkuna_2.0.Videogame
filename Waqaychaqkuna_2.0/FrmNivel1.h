#pragma once
#include "Guardia.h"
#include "GestorEscenario1.h"

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
			guardia = new Guardia(20, 20, 5, 5, 1, true);
			gestor = new GestorEscenario1(guardia, this->pnlMapa->Width, this->pnlMapa->Height,10);
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
		   GestorEscenario1* gestor;
		   Guardia* guardia;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmNivel1::typeid));
			   this->tmrNivel1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlMapa = (gcnew System::Windows::Forms::Panel());
			   this->SuspendLayout();
			   // 
			   // tmrNivel1
			   // 
			   this->tmrNivel1->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer1_Tick);
			   // 
			   // pnlMapa
			   // 
			   this->pnlMapa->BackColor = System::Drawing::Color::White;
			   this->pnlMapa->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlMapa.BackgroundImage")));
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
			   this->Controls->Add(this->pnlMapa);
			   this->Name = L"FrmNivel1";
			   this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->Text = L"Nivel 1: Museo ";
			   this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmNivel1_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyDown);
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private:
		Void FrmNivel1_Load(System::Object^ sender, System::EventArgs^ e) {
			BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
			Graphics^ g = this->pnlMapa->CreateGraphics();
			buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
			tmrNivel1->Start();
			delete g;

		}
		Void FrmNivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Up) {
				gestor->moverGuardia(Direccion::Arriba);
				Pintar();
			}

			else if (e->KeyCode == Keys::Down) {
				gestor->moverGuardia(Direccion::Abajo);
				Pintar();
			}

			else if (e->KeyCode == Keys::Right) {
				gestor->moverGuardia(Direccion::Derecha);
				Pintar();
			}

			else if (e->KeyCode == Keys::Left) {
				gestor->moverGuardia(Direccion::Izquierda);
				Pintar();
			}
		}
		Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			
			gestor->jugar();

			Pintar();
		}

		Void Pintar()
		{
			if (this->pnlMapa->BackgroundImage != nullptr)
			{
				buffer->Graphics->DrawImage(this->pnlMapa->BackgroundImage,
					0, 0,
					this->pnlMapa->Width,
					this->pnlMapa->Height);
			}
			else
				buffer->Graphics->Clear(this->pnlMapa->BackColor);

			gestor->dibujar(buffer->Graphics);

			Graphics^ g = this->pnlMapa->CreateGraphics();
			buffer->Render(g);
			delete g;
		}

	};
}
