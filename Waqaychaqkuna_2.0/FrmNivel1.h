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
			gestor = new GestorMuseo(10);
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
			   this->lblPrueba->Location = System::Drawing::Point(1342, 305);
			   this->lblPrueba->Name = L"lblPrueba";
			   this->lblPrueba->Size = System::Drawing::Size(35, 13);
			   this->lblPrueba->TabIndex = 1;
			   this->lblPrueba->Text = L"label1";
			   // 
			   // FrmNivel1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1600, 800);
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

			BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
			Graphics^ g = this->pnlMapa->CreateGraphics();
			buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
			tmrNivel1->Start();
			delete g;

		}
		Void FrmNivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Up) {
				gestor->setVelGuardia(0, -5);
				this->lblPrueba->Text = String::Format(L"DX: {0}, DY: {1}", gestor->getGuardia()->getDirX(), gestor->getGuardia()->getDirY());
			}
			else if (e->KeyCode == Keys::Down) {
				gestor->setVelGuardia(0, 5);
				this->lblPrueba->Text = String::Format(L"DX: {0}, DY: {1}", gestor->getGuardia()->getDirX(), gestor->getGuardia()->getDirY());
			}
			else if (e->KeyCode == Keys::Right) {
				gestor->setVelGuardia(5, 0);
				this->lblPrueba->Text = String::Format(L"DX: {0}, DY: {1}", gestor->getGuardia()->getDirX(), gestor->getGuardia()->getDirY());
			}
			else if (e->KeyCode == Keys::Left) {
				gestor->setVelGuardia(-5, 0);
				this->lblPrueba->Text = String::Format(L"DX: {0}, DY: {1}", gestor->getGuardia()->getDirX(), gestor->getGuardia()->getDirY());
			}
		}
		Void tmrNivel1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			gestor->mover();
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
			gestor->setVelGuardia(0, 0);
			this->lblPrueba->Text = String::Format(L"DX: {0}, DY: {1}", gestor->getGuardia()->getDirX(), gestor->getGuardia()->getDirY());
		}
};
}
