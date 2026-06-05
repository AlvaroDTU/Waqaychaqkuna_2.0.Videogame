#pragma once
#include "Guardia.h"

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

			g = this->CreateGraphics();
			guardia = new Guardia("gaurdia", 20, 20, 240, 20, 5, 5, 1, true);
			guardiaImg = gcnew Bitmap("guardia.png");
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

		Graphics^ g;
	private: System::Windows::Forms::Timer^ juego;

		   Guardia* guardia;
		   Bitmap^ guardiaImg;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->juego = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// juego
			// 
			this->juego->Tick += gcnew System::EventHandler(this, &FrmNivel1::timer1_Tick);
			// 
			// FrmNivel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(943, 543);
			this->Name = L"FrmNivel1";
			this->Text = L"FrmNivel1";
			this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmNivel1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void FrmNivel1_Load(System::Object^ sender, System::EventArgs^ e) {
			juego->Start();

		}
	private: System::Void FrmNivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Up) {
			guardia->mover(Direccion::Arriba);
		}

		else if (e->KeyCode == Keys::Down) {
			guardia->mover(Direccion::Abajo);
		}

		else if (e->KeyCode == Keys::Right) {
			guardia->mover(Direccion::Derecha);
		}

		else if (e->KeyCode == Keys::Left) {
			guardia->mover(Direccion::Izquierda);


		}
		

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		g->Clear(Color::Cyan);

		guardia->dibujar(g,guardiaImg);
	}

	};
}
