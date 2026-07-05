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
	private: System::Windows::Forms::Panel^ pnlMapa;
	private: System::Windows::Forms::Panel^ pnlEstadisticas;
	private: System::Windows::Forms::Timer^ tmrNivel1;
	private: System::Windows::Forms::Label^ lblPista;
	private: System::Windows::Forms::Label^ lblIntentos;
	private: System::Windows::Forms::Label^ lblDerrotados;
	private: System::Windows::Forms::Label^ lblArtilugio1;
	private: System::Windows::Forms::Label^ lblArtilugio2;
	private: System::Windows::Forms::Label^ lblArtilugio3;
	private: System::Windows::Forms::Label^ lblArtilugio4;
	private: System::Windows::Forms::Label^ lblArtilugio5;
	private: System::Windows::Forms::Label^ lblArtilugio6;
		   BufferedGraphics^ buffer;
		   GestorMuseo* gestor;
		   bool musicaSuspenso = false;
		   bool musicaFinal = false;
		   int finCont = 0;
		   float mapa_escalaX = 1.0f;
		   float mapa_escalaY = 1.0f;
		   float stats_escalaX = 1.0f;
		   float stats_escalaY = 1.0f;
		   Point lblPistaBase;
		   Point lblIntentosBase;
		   Point lblDerrotadosBase;
		   Point lblArtilugio1Base;
		   Point lblArtilugio2Base;
		   Point lblArtilugio3Base;
		   Point lblArtilugio4Base;
		   Point lblArtilugio5Base;
		   Point lblArtilugio6Base;

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
			   this->pnlEstadisticas = (gcnew System::Windows::Forms::Panel());
			   this->lblArtilugio1 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio2 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio3 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio4 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio5 = (gcnew System::Windows::Forms::Label());
			   this->lblArtilugio6 = (gcnew System::Windows::Forms::Label());
			   this->lblIntentos = (gcnew System::Windows::Forms::Label());
			   this->lblDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblPista = (gcnew System::Windows::Forms::Label());
			   this->pnlEstadisticas->SuspendLayout();
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
			   // pnlEstadisticas
			   // 
			   this->pnlEstadisticas->BackColor = System::Drawing::Color::Transparent;
			   this->pnlEstadisticas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pnlEstadisticas->Controls->Add(this->lblArtilugio1);
			   this->pnlEstadisticas->Controls->Add(this->lblArtilugio2);
			   this->pnlEstadisticas->Controls->Add(this->lblArtilugio3);
			   this->pnlEstadisticas->Controls->Add(this->lblArtilugio4);
			   this->pnlEstadisticas->Controls->Add(this->lblArtilugio5);
			   this->pnlEstadisticas->Controls->Add(this->lblArtilugio6);
			   this->pnlEstadisticas->Controls->Add(this->lblIntentos);
			   this->pnlEstadisticas->Controls->Add(this->lblDerrotados);
			   this->pnlEstadisticas->Controls->Add(this->lblPista);
			   this->pnlEstadisticas->Location = System::Drawing::Point(1300, 0);
			   this->pnlEstadisticas->Name = L"pnlEstadisticas";
			   this->pnlEstadisticas->Size = System::Drawing::Size(300, 800);
			   this->pnlEstadisticas->TabIndex = 10;
			   this->pnlEstadisticas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmNivel1::pnlEstadisticas_Paint);
			   // 
			   // lblArtilugio1
			   // 
			   this->lblArtilugio1->AutoSize = true;
			   this->lblArtilugio1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio1->Location = System::Drawing::Point(18, 446);
			   this->lblArtilugio1->Name = L"lblArtilugio1";
			   this->lblArtilugio1->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio1->TabIndex = 1;
			   this->lblArtilugio1->Text = L"ARTILUGIO 1:";
			   // 
			   // lblArtilugio2
			   // 
			   this->lblArtilugio2->AutoSize = true;
			   this->lblArtilugio2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio2->Location = System::Drawing::Point(18, 509);
			   this->lblArtilugio2->Name = L"lblArtilugio2";
			   this->lblArtilugio2->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio2->TabIndex = 4;
			   this->lblArtilugio2->Text = L"ARTILUGIO 2:";
			   // 
			   // lblArtilugio3
			   // 
			   this->lblArtilugio3->AutoSize = true;
			   this->lblArtilugio3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio3->Location = System::Drawing::Point(18, 575);
			   this->lblArtilugio3->Name = L"lblArtilugio3";
			   this->lblArtilugio3->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio3->TabIndex = 6;
			   this->lblArtilugio3->Text = L"ARTILUGIO 3:";
			   // 
			   // lblArtilugio4
			   // 
			   this->lblArtilugio4->AutoSize = true;
			   this->lblArtilugio4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio4->Location = System::Drawing::Point(165, 446);
			   this->lblArtilugio4->Name = L"lblArtilugio4";
			   this->lblArtilugio4->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio4->TabIndex = 7;
			   this->lblArtilugio4->Text = L"ARTILUGIO 4:";
			   // 
			   // lblArtilugio5
			   // 
			   this->lblArtilugio5->AutoSize = true;
			   this->lblArtilugio5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio5->Location = System::Drawing::Point(165, 509);
			   this->lblArtilugio5->Name = L"lblArtilugio5";
			   this->lblArtilugio5->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio5->TabIndex = 8;
			   this->lblArtilugio5->Text = L"ARTILUGIO 5:";
			   // 
			   // lblArtilugio6
			   // 
			   this->lblArtilugio6->AutoSize = true;
			   this->lblArtilugio6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblArtilugio6->Location = System::Drawing::Point(165, 575);
			   this->lblArtilugio6->Name = L"lblArtilugio6";
			   this->lblArtilugio6->Size = System::Drawing::Size(110, 17);
			   this->lblArtilugio6->TabIndex = 9;
			   this->lblArtilugio6->Text = L"ARTILUGIO 6:";
			   // 
			   // lblIntentos
			   // 
			   this->lblIntentos->AutoSize = true;
			   this->lblIntentos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblIntentos->Location = System::Drawing::Point(6, 700);
			   this->lblIntentos->Name = L"lblIntentos";
			   this->lblIntentos->Size = System::Drawing::Size(105, 17);
			   this->lblIntentos->TabIndex = 5;
			   this->lblIntentos->Text = L"INTENTOS: 0";
			   // 
			   // lblDerrotados
			   // 
			   this->lblDerrotados->AutoSize = true;
			   this->lblDerrotados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblDerrotados->Location = System::Drawing::Point(6, 727);
			   this->lblDerrotados->Name = L"lblDerrotados";
			   this->lblDerrotados->Size = System::Drawing::Size(221, 17);
			   this->lblDerrotados->TabIndex = 3;
			   this->lblDerrotados->Text = L"ENEMIGOS DERROTADOS: 0";
			   // 
			   // lblPista
			   // 
			   this->lblPista->AutoSize = true;
			   this->lblPista->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblPista->Location = System::Drawing::Point(6, 760);
			   this->lblPista->Name = L"lblPista";
			   this->lblPista->Size = System::Drawing::Size(122, 17);
			   this->lblPista->TabIndex = 2;
			   this->lblPista->Text = L"PISTA ACTUAL:\n";
			   this->lblPista->Visible = false;
			   // 
			   // FrmNivel1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1600, 800);
			   this->Controls->Add(this->pnlMapa);
			   this->Controls->Add(this->pnlEstadisticas);
			   this->Name = L"FrmNivel1";
			   this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->Text = L"Nivel 1: Museo";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FrmNivel1::FrmNivel1_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &FrmNivel1::FrmNivel1_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel1::FrmNivel1_KeyUp);
			   this->Resize += gcnew System::EventHandler(this, &FrmNivel1::FrmNivel1_Resize);
			   this->pnlEstadisticas->ResumeLayout(false);
			   this->pnlEstadisticas->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private:
		Void FrmNivel1_Load(System::Object^ sender, System::EventArgs^ e) {

			gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);
			gestor->crearSprites();
			lblPistaBase = lblPista->Location;
			lblIntentosBase = lblIntentos->Location;
			lblDerrotadosBase = lblDerrotados->Location;
			lblArtilugio1Base = lblArtilugio1->Location;
			lblArtilugio2Base = lblArtilugio2->Location;
			lblArtilugio3Base = lblArtilugio3->Location;
			lblArtilugio4Base = lblArtilugio4->Location;
			lblArtilugio5Base = lblArtilugio5->Location;
			lblArtilugio6Base = lblArtilugio6->Location;

			BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
			Graphics^ g = this->pnlMapa->CreateGraphics();
			buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
			tmrNivel1->Start();

			Recursos::normal1->PlayLooping();
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
			if (tPista == 1) this->lblPista->Text = L"PISTA ACTUAL:\nBANDANA EN LAS PIERNAS";
			if (tPista == 2) this->lblPista->Text = L"PISTA ACTUAL:\nBANDANA EN LOS BRAZOS";
			if (tPista == 3) this->lblPista->Text = L"PISTA ACTUAL:\nCAMISAS NEGRAS";

			lblArtilugio1->Text = String::Format("Puntaje\nCabeza Clava:\n{0}", gestor->getBien(0)->getPuntajeValor());
			lblArtilugio2->Text = String::Format("Puntaje\nManto Paracas:\n{0}", gestor->getBien(1)->getPuntajeValor());
			lblArtilugio3->Text = String::Format("Puntaje\nCraneo Paracas:\n{0}", gestor->getBien(2)->getPuntajeValor());
			lblArtilugio4->Text = String::Format("Puntaje\nHuaco Moche:\n{0}", gestor->getBien(3)->getPuntajeValor());
			lblArtilugio5->Text = String::Format("Puntaje\nTumi de Oro:\n{0}", gestor->getBien(4)->getPuntajeValor());
			lblArtilugio6->Text = String::Format("Puntaje\nVaso Kero:\n{0}", gestor->getBien(5)->getPuntajeValor());

			this->lblDerrotados->Text = String::Format(L"ENEMIGOS CAPTURADOS: {0}", gestor->getCapturados());
			this->lblIntentos->Text = String::Format(L"INTENTOS: {0}", gestor->getIntentos());

			if (!musicaSuspenso &&
				(gestor->getBien(0)->getPuntajeValor() <= 500 ||
					gestor->getBien(1)->getPuntajeValor() <= 500 ||
					gestor->getBien(2)->getPuntajeValor() <= 500 ||
					gestor->getBien(3)->getPuntajeValor() <= 500))
			{
				musicaSuspenso = true;

				Recursos::normal1->Stop();
				Recursos::suspenso1->PlayLooping();
			}

			Pintar();

			if (gestor->victoria() || gestor->derrota())
			{
				if (gestor->victoria() && !musicaFinal) {
					Recursos::normal1->Stop();
					Recursos::suspenso1->Stop();
					Recursos::victoria->PlayLooping();
					musicaFinal = true;
				}
				if (gestor->derrota() && !musicaFinal) {
					Recursos::normal1->Stop();
					Recursos::suspenso1->Stop();
					Recursos::perdiste->PlayLooping();
					musicaFinal = true;
				}
				finCont++;
				if (finCont >= 200)
				{
					this->tmrNivel1->Stop();
					if (gestor->victoria())
					{
						Recursos::victoria->Stop();
						this->DialogResult = System::Windows::Forms::DialogResult::OK;
					}
					if (gestor->derrota())
						Recursos::perdiste->Stop();
					this->Close();
				}
			}
		}
		Void Pintar()
		{
			gestor->dibujar(buffer->Graphics);
			Graphics^ g = this->pnlMapa->CreateGraphics();
			if (gestor->victoria()) {
				System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Segoe UI", 40, FontStyle::Bold);
				String^ text = "MISION CUMPLIDA!";
				SizeF textSize = buffer->Graphics->MeasureString(text, fuente);
				// centro
				float x = (buffer->Graphics->VisibleClipBounds.Width - textSize.Width) / 2.0f;
				float y = (buffer->Graphics->VisibleClipBounds.Height - textSize.Height) / 2.0f;

				buffer->Graphics->DrawString(text,fuente,gcnew SolidBrush(Color::DarkGreen), x, y);

			}
			if (gestor->derrota()) {
				System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Segoe UI", 40, FontStyle::Bold);
				String^ text = "GAME OVER :C";
				SizeF textSize = buffer->Graphics->MeasureString(text, fuente);
				// centro
				float x = (buffer->Graphics->VisibleClipBounds.Width - textSize.Width) / 2.0f;
				float y = (buffer->Graphics->VisibleClipBounds.Height - textSize.Height) / 2.0f;
				buffer->Graphics->DrawString(text, fuente, gcnew SolidBrush(Color::DarkGreen), x, y);

			}
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
	private: System::Void FrmNivel1_Resize(System::Object^ sender, System::EventArgs^ e)
	{
		if (buffer == nullptr)
			return;
		pnlMapa->Width = (13 * this->ClientSize.Width) / 16.0f;
		pnlMapa->Height = this->ClientSize.Height;

		pnlEstadisticas->Width = (3 * this->ClientSize.Width) / 16.0f;
		pnlEstadisticas->Height = this->ClientSize.Height;
		pnlEstadisticas->Left = this->ClientSize.Width - pnlEstadisticas->Width;

		mapa_escalaX = pnlMapa->Width / 1300.0f;
		mapa_escalaY = pnlMapa->Height / 800.0f;

		stats_escalaX = pnlEstadisticas->Width / 300.0f;
		stats_escalaY = pnlEstadisticas->Height / 800.0f;

		ActualizarTamanoLabels();

		gestor->setEscalado(mapa_escalaX, mapa_escalaY);
		gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);

		delete buffer;
		BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
		Graphics^ g = pnlMapa->CreateGraphics();
		buffer = contexto->Allocate(g, pnlMapa->ClientRectangle);
		buffer->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
		delete g;

		Pintar();
	}

	Void ActualizarTamanoLabels()
	{
		int tmFuente = 10;
		float escalaPromedio = stats_escalaX;
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font(
										"Microsoft Sans Serif",
										(int)tmFuente * escalaPromedio,
										FontStyle::Bold
										);
		lblPista->Location = Point(
			lblPistaBase.X * stats_escalaX,
			lblPistaBase.Y * stats_escalaY
		);
		lblPista->Font = fuente;

		lblIntentos->Location = Point(
			lblIntentosBase.X * stats_escalaX,
			lblIntentosBase.Y * stats_escalaY
		);
		lblIntentos->Font = fuente;

		lblDerrotados->Location = Point(
			lblDerrotadosBase.X * stats_escalaX,
			lblDerrotadosBase.Y * stats_escalaY
		);
		lblDerrotados->Font = fuente;

		lblArtilugio1->Location = Point(
			lblArtilugio1Base.X * stats_escalaX,
			lblArtilugio1Base.Y * stats_escalaY
		);
		lblArtilugio1->Font = fuente;

		lblArtilugio2->Location = Point(
			lblArtilugio2Base.X * stats_escalaX,
			lblArtilugio2Base.Y * stats_escalaY
		);
		lblArtilugio2->Font = fuente;

		lblArtilugio3->Location = Point(
			lblArtilugio3Base.X * stats_escalaX,
			lblArtilugio3Base.Y * stats_escalaY
		);
		lblArtilugio3->Font = fuente;

		lblArtilugio4->Location = Point(
			lblArtilugio4Base.X * stats_escalaX,
			lblArtilugio4Base.Y * stats_escalaY
		);
		lblArtilugio4->Font = fuente;

		lblArtilugio5->Location = Point(
			lblArtilugio5Base.X * stats_escalaX,
			lblArtilugio5Base.Y * stats_escalaY
		);
		lblArtilugio5->Font = fuente;

		lblArtilugio6->Location = Point(
			lblArtilugio6Base.X * stats_escalaX,
			lblArtilugio6Base.Y * stats_escalaY
		);
		lblArtilugio6->Font = fuente;
	}
	Void FrmNivel1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) 
	{
		Recursos::normal1->Stop();
		Recursos::suspenso1->Stop();
		Recursos::victoria->Stop();
		Recursos::perdiste->Stop();
	}
	Void pnlEstadisticas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		Graphics^ g = e->Graphics;
		g->DrawImage(gcnew Bitmap("backgrounds\\PanelEstadisticas1.png"), this->pnlEstadisticas->ClientRectangle);
	}
};
}
