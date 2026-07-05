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
			gestor = new GestorHuacas(20);
			finCont = 0;

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
	private: System::Windows::Forms::Label^ lblHuaca1;
	private: System::Windows::Forms::Label^ lblHuaca2;
	private: System::Windows::Forms::Label^ lblHuaca3;
	private: System::Windows::Forms::Label^ lblHuaca4;
	private: System::Windows::Forms::Label^ lblHuacaN1;
	private: System::Windows::Forms::Label^ lblHuacaN2;
	private: System::Windows::Forms::Label^ lblHuacaN3;
	private: System::Windows::Forms::Label^ lblHuacaN4;
	int finCont;
	
		   BufferedGraphics^ buffer;
		   bool dialogoHuaca1 = false;
		   bool dialogoHuaca2 = false;
		   bool dialogoHuaca3 = false;
		   bool dialogoHuaca4 = false;
		   bool musicaSuspenso = false;
		   Point lblHuacaN1Base;
		   Point lblHuaca1Base;
		   Point lblHuacaN2Base;
		   Point lblHuaca2Base;
		   Point lblHuacaN3Base;
		   Point lblHuaca3Base;
		   Point lblHuacaN4Base;
		   Point lblHuaca4Base;
		   float mapa_escalaX = 1.0f;
		   float mapa_escalaY = 1.0f;
		   float stats_escalaX = 1.0f;
		   float stats_escalaY = 1.0f;
	private: System::Windows::Forms::Panel^ pnlEstadisticas;



		   bool musicaFinal = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmNivel2::typeid));
			this->pnlMapa = (gcnew System::Windows::Forms::Panel());
			this->pnlEstadisticas = (gcnew System::Windows::Forms::Panel());
			this->lblPrueba = (gcnew System::Windows::Forms::Label());
			this->lblHuaca4 = (gcnew System::Windows::Forms::Label());
			this->lblHuacaN4 = (gcnew System::Windows::Forms::Label());
			this->lblPrueba2 = (gcnew System::Windows::Forms::Label());
			this->lblHuacaN3 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca3 = (gcnew System::Windows::Forms::Label());
			this->lblHuacaN1 = (gcnew System::Windows::Forms::Label());
			this->lblHuacaN2 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca1 = (gcnew System::Windows::Forms::Label());
			this->lblHuaca2 = (gcnew System::Windows::Forms::Label());
			this->tmrJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlEstadisticas->SuspendLayout();
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
			// pnlEstadisticas
			// 
			this->pnlEstadisticas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlEstadisticas.BackgroundImage")));
			this->pnlEstadisticas->Controls->Add(this->lblPrueba);
			this->pnlEstadisticas->Controls->Add(this->lblHuaca4);
			this->pnlEstadisticas->Controls->Add(this->lblHuacaN4);
			this->pnlEstadisticas->Controls->Add(this->lblPrueba2);
			this->pnlEstadisticas->Controls->Add(this->lblHuacaN3);
			this->pnlEstadisticas->Controls->Add(this->lblHuaca3);
			this->pnlEstadisticas->Controls->Add(this->lblHuacaN1);
			this->pnlEstadisticas->Controls->Add(this->lblHuacaN2);
			this->pnlEstadisticas->Controls->Add(this->lblHuaca1);
			this->pnlEstadisticas->Controls->Add(this->lblHuaca2);
			this->pnlEstadisticas->Location = System::Drawing::Point(1300, 0);
			this->pnlEstadisticas->Name = L"pnlEstadisticas";
			this->pnlEstadisticas->Size = System::Drawing::Size(300, 800);
			this->pnlEstadisticas->TabIndex = 0;
			// 
			// lblPrueba
			// 
			this->lblPrueba->AutoSize = true;
			this->lblPrueba->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrueba->Location = System::Drawing::Point(26, 429);
			this->lblPrueba->Name = L"lblPrueba";
			this->lblPrueba->Size = System::Drawing::Size(81, 19);
			this->lblPrueba->TabIndex = 2;
			this->lblPrueba->Text = L"label1";
			// 
			// lblHuaca4
			// 
			this->lblHuaca4->AutoSize = true;
			this->lblHuaca4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca4->Location = System::Drawing::Point(26, 719);
			this->lblHuaca4->Name = L"lblHuaca4";
			this->lblHuaca4->Size = System::Drawing::Size(81, 19);
			this->lblHuaca4->TabIndex = 7;
			this->lblHuaca4->Text = L"label1";
			// 
			// lblHuacaN4
			// 
			this->lblHuacaN4->AutoSize = true;
			this->lblHuacaN4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuacaN4->Location = System::Drawing::Point(26, 695);
			this->lblHuacaN4->Name = L"lblHuacaN4";
			this->lblHuacaN4->Size = System::Drawing::Size(81, 19);
			this->lblHuacaN4->TabIndex = 11;
			this->lblHuacaN4->Text = L"label1";
			// 
			// lblPrueba2
			// 
			this->lblPrueba2->AutoSize = true;
			this->lblPrueba2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrueba2->Location = System::Drawing::Point(26, 463);
			this->lblPrueba2->Name = L"lblPrueba2";
			this->lblPrueba2->Size = System::Drawing::Size(81, 19);
			this->lblPrueba2->TabIndex = 3;
			this->lblPrueba2->Text = L"label1";
			// 
			// lblHuacaN3
			// 
			this->lblHuacaN3->AutoSize = true;
			this->lblHuacaN3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuacaN3->Location = System::Drawing::Point(26, 632);
			this->lblHuacaN3->Name = L"lblHuacaN3";
			this->lblHuacaN3->Size = System::Drawing::Size(81, 19);
			this->lblHuacaN3->TabIndex = 10;
			this->lblHuacaN3->Text = L"label1";
			// 
			// lblHuaca3
			// 
			this->lblHuaca3->AutoSize = true;
			this->lblHuaca3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca3->Location = System::Drawing::Point(26, 664);
			this->lblHuaca3->Name = L"lblHuaca3";
			this->lblHuaca3->Size = System::Drawing::Size(81, 19);
			this->lblHuaca3->TabIndex = 6;
			this->lblHuaca3->Text = L"label1";
			// 
			// lblHuacaN1
			// 
			this->lblHuacaN1->AutoSize = true;
			this->lblHuacaN1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuacaN1->Location = System::Drawing::Point(26, 501);
			this->lblHuacaN1->Name = L"lblHuacaN1";
			this->lblHuacaN1->Size = System::Drawing::Size(81, 19);
			this->lblHuacaN1->TabIndex = 8;
			this->lblHuacaN1->Text = L"label1";
			// 
			// lblHuacaN2
			// 
			this->lblHuacaN2->AutoSize = true;
			this->lblHuacaN2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuacaN2->Location = System::Drawing::Point(26, 567);
			this->lblHuacaN2->Name = L"lblHuacaN2";
			this->lblHuacaN2->Size = System::Drawing::Size(81, 19);
			this->lblHuacaN2->TabIndex = 9;
			this->lblHuacaN2->Text = L"label1";
			// 
			// lblHuaca1
			// 
			this->lblHuaca1->AutoSize = true;
			this->lblHuaca1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHuaca1->Location = System::Drawing::Point(26, 530);
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
			this->lblHuaca2->Location = System::Drawing::Point(26, 597);
			this->lblHuaca2->Name = L"lblHuaca2";
			this->lblHuaca2->Size = System::Drawing::Size(81, 19);
			this->lblHuaca2->TabIndex = 5;
			this->lblHuaca2->Text = L"label1";
			// 
			// tmrJuego
			// 
			this->tmrJuego->Interval = 16;
			this->tmrJuego->Tick += gcnew System::EventHandler(this, &FrmNivel2::tmrJuego_Tick);
			// 
			// FrmNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->pnlEstadisticas);
			this->Controls->Add(this->pnlMapa);
			this->Name = L"FrmNivel2";
			this->Text = L"FrmNivel2";
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmNivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel2::FrmNivel2_KeyUp);
			this->pnlEstadisticas->ResumeLayout(false);
			this->pnlEstadisticas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmNivel2_Load(System::Object^ sender, System::EventArgs^ e) {
		gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);
		gestor->crearSprites();
		lblHuaca1Base = lblHuaca1->Location;
		lblHuacaN1Base = lblHuacaN1->Location;
		lblHuaca2Base = lblHuaca2->Location;
		lblHuacaN2Base = lblHuacaN2->Location;
		lblHuaca3Base = lblHuaca3->Location;
		lblHuacaN3Base = lblHuacaN3->Location;
		lblHuaca4Base = lblHuaca4->Location;
		lblHuacaN4Base = lblHuacaN4->Location;
		//prueba de dialogo
		std::vector<std::string> frases;
		frases.push_back("Reportera: ¡Necesitamos tu ayuda para proteger nuestro patrimonio cultural!");
		frases.push_back("Usa la tecla E para colocar cuidadores cerca de las huacas y detener a los huaqueros.");
		frases.push_back("Cada huaca conserva siglos de historia. Si una cae, también se pierde parte de nuestra identidad.");
		frases.push_back("Vigila su puntaje: si desciende por debajo de 1500, la huaca será destruida. ¡Depende de ti evitarlo!");
		gestor->getDialogo()->iniciar(frases);

	/*  
		"Huaca del Sol", 1));
		"Huaca de la Luna", 2
		"Huaca Dragon", 3));
		"Huaca Takaynamo", 4))
	*/
		BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
		Graphics^ g = this->pnlMapa->CreateGraphics();
		buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
		tmrJuego->Start();
		Recursos::normal2->PlayLooping();
		delete g;
	}
	private: System::Void FrmNivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	//prueba dialogos
		if (gestor->getDialogo()->estaActivo())
		{
			if (e->KeyCode == Keys::Space || e->KeyCode == Keys::Enter)
				gestor->getDialogo()->avanzar();
			e->Handled = true;
			return;
		}

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
	  gestor->getDialogo()->dibujar(buffer->Graphics, pnlMapa->ClientSize.Width, pnlMapa->ClientSize.Height);
	  if (gestor->victoria()) {
		  buffer->Graphics->DrawString("MISION CUMPLIDA!", gcnew System::Drawing::Font("Segoe UI", 40, FontStyle::Bold),
			  gcnew SolidBrush(Color::DarkGreen), 300.0f, 260.0f);

	  }
	  if (gestor->derrota()) {
		  buffer->Graphics->DrawString("GAME OVER", gcnew System::Drawing::Font("Segoe UI", 40, FontStyle::Bold),
			  gcnew SolidBrush(Color::DarkRed), 360.0f, 260.0f);

	  }
	  Graphics^ g = this->pnlMapa->CreateGraphics();
	  buffer->Render(g);
	  delete g;
	 }
	 private: System::Void FrmNivel2_Resize(System::Object^ sender, System::EventArgs^ e)
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
				lblHuaca1->Location = Point(lblHuaca1Base.X * stats_escalaX,lblHuaca1Base.Y * stats_escalaY);
				lblHuaca1->Font = fuente;
				lblHuacaN1->Location = Point(lblHuacaN1Base.X * stats_escalaX, lblHuacaN1Base.Y * stats_escalaY);
				lblHuacaN1->Font = fuente;

				lblHuaca2->Location = Point(lblHuaca2Base.X * stats_escalaX, lblHuaca2Base.Y * stats_escalaY);
				lblHuaca2->Font = fuente;
				lblHuacaN2->Location = Point(lblHuacaN2Base.X * stats_escalaX, lblHuacaN2Base.Y * stats_escalaY);
				lblHuacaN2->Font = fuente;

				lblHuaca3->Location = Point(lblHuaca3Base.X * stats_escalaX, lblHuaca3Base.Y * stats_escalaY);
				lblHuaca3->Font = fuente;
				lblHuacaN3->Location = Point(lblHuacaN3Base.X * stats_escalaX, lblHuacaN3Base.Y * stats_escalaY);
				lblHuacaN3->Font = fuente;

				lblHuaca4->Location = Point(lblHuaca4Base.X * stats_escalaX,lblHuaca4Base.Y * stats_escalaY);
				lblHuaca4->Font = fuente;
				lblHuacaN4->Location = Point(lblHuacaN4Base.X * stats_escalaX, lblHuacaN4Base.Y * stats_escalaY);
				lblHuacaN4->Font = fuente;
				
			}

	private: System::Void FrmNivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Guardia* g = gestor->getGuardia();
		g->setVelocidad(0, 0);
	}
	Void tmrJuego_Tick(System::Object^ sender, System::EventArgs^ e) {

		gestor->getDialogo()->actualizar();
		if (gestor->victoria() || gestor->derrota())
		{
			if (gestor->victoria() && !musicaFinal) {
				Recursos::normal2->Stop();
				Recursos::suspenso2->Stop();
				Recursos::victoria->PlayLooping();
				musicaFinal = true;
			}
			if (gestor->derrota() && !musicaFinal) {
				Recursos::normal2->Stop();
				Recursos::suspenso2->Stop();
				Recursos::perdiste->PlayLooping();
				musicaFinal = true;
			}
			finCont++;
			if (finCont >= 200)
			{
				this->tmrJuego->Stop();
				if (gestor->victoria()) { Recursos::victoria->Stop();
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				}
				if (gestor->derrota()) Recursos::perdiste->Stop();
				this->Close();
			}
		}

		if (!musicaSuspenso &&
			(gestor->getBien(0)->getPuntajeValor() <= 1500 ||
				gestor->getBien(1)->getPuntajeValor() <= 1500 ||
				gestor->getBien(2)->getPuntajeValor() <= 1500 ||
				gestor->getBien(3)->getPuntajeValor() <= 1500))
		{
			musicaSuspenso = true;

			Recursos::normal2->Stop();
			Recursos::suspenso2->PlayLooping();
		}


		if (!dialogoHuaca1 && gestor->getBien(0)->getPuntajeValor() <= 1500)
		{
			dialogoHuaca1 = true;

			std::vector<std::string> huaca1;
			huaca1.push_back("La Huaca del Sol ha sido destruida...");
			huaca1.push_back("Fue el mayor centro ceremonial de la cultura Moche.");
			huaca1.push_back("Con ella se pierde parte de la historia y arquitectura del Perú.");
			huaca1.push_back("¡Protege nuestro patrimonio antes de que sea demasiado tarde!");

			gestor->getDialogo()->iniciar(huaca1);
		}

		if (!dialogoHuaca2 && gestor->getBien(1)->getPuntajeValor() <= 1500)
		{
			dialogoHuaca2 = true;

			std::vector<std::string> huaca2;
			huaca2.push_back("La Huaca de la Luna ha sido destruida...");
			huaca2.push_back("Sus murales narraban rituales y creencias de los mochicas.");
			huaca2.push_back("Cada pintura perdida borra parte de nuestra memoria cultural.");
			huaca2.push_back("¡No permitas que el huaqueo destruya nuestra historia!");

			gestor->getDialogo()->iniciar(huaca2);
		}
		//hOLA

		if (!dialogoHuaca3 && gestor->getBien(2)->getPuntajeValor() <= 1500)
		{
			dialogoHuaca3 = true;

			std::vector<std::string> huaca3;
			huaca3.push_back("La Huaca Dragón ha sido destruida...");
			huaca3.push_back("Sus relieves representaban importantes símbolos de la cultura Chimú.");
			huaca3.push_back("Su destrucción significa perder valiosa evidencia arqueológica.");
			huaca3.push_back("¡El patrimonio cultural necesita ser protegido por todos!");

			gestor->getDialogo()->iniciar(huaca3);
		}

		if (!dialogoHuaca4 && gestor->getBien(3)->getPuntajeValor() <= 1500)
		{
			dialogoHuaca4 = true;

			std::vector<std::string> huaca4;
			huaca4.push_back("La Huaca Takaynamo ha sido destruida...");
			huaca4.push_back("Está vinculada al origen legendario del reino Chimú.");
			huaca4.push_back("Cada monumento perdido debilita nuestra identidad cultural.");
			huaca4.push_back("¡Conservar el patrimonio es preservar nuestra historia!");

			gestor->getDialogo()->iniciar(huaca4);
		}

	lblPrueba->Text = String::Format("PosX: {0}", gestor->getGuardia()->getPosX());
	lblHuaca1->Text = String::Format("Puntaje: {0}", gestor->getBien(0)->getPuntajeValor());
	lblHuacaN1->Text = gcnew System::String(gestor->getBien(0)->getNombre().c_str());
	lblHuaca2->Text = String::Format("Puntaje: {0}", gestor->getBien(1)->getPuntajeValor());
	lblHuacaN2->Text = gcnew System::String(gestor->getBien(1)->getNombre().c_str());
	lblHuaca3->Text = String::Format("Puntaje: {0}", gestor->getBien(2)->getPuntajeValor());
	lblHuacaN3->Text = gcnew System::String(gestor->getBien(2)->getNombre().c_str());
	lblHuaca4->Text = String::Format("Puntaje: {0}", gestor->getBien(3)->getPuntajeValor());
	lblHuacaN4->Text = gcnew System::String(gestor->getBien(3)->getNombre().c_str());

	if (!gestor->getDialogo()->estaActivo()) { gestor->jugar(); 
	gestor->detectarColisiones();}

	Pintar();


}
};
}
