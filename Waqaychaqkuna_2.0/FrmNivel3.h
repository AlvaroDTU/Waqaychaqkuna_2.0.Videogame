#pragma once
#include <msclr/marshal_cppstd.h> 
#include "Guardia.h"
#include "GestorBiblioteca.h"

namespace Waqaychaqkuna20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmNivel3
	/// </summary>
	public ref class FrmNivel3 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel3(int p,String^ nom)
		{
			gestor = new GestorBiblioteca();
			InitializeComponent();
			finCont = 0;
			puntajeFinal = p;
			nombre = nom;
			//
			//TODO: agregar código de constructor aquí
			//
		}
		int RetornarPuntaje() {
			return gestor->getPuntaje();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmNivel3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlMapa;



	private: System::Windows::Forms::Label^ lblArchivo1;
	private: System::Windows::Forms::Label^ lblArchivo2;
	private: System::Windows::Forms::Label^ lblArchivo3;
	private: System::Windows::Forms::Label^ lblArchivo4;
	private: System::Windows::Forms::Label^ lblDerrotados;
	private: System::Windows::Forms::Label^ lblBateria;
	private: System::Windows::Forms::Label^ lblIntentos;
	private: System::Windows::Forms::Timer^ tmrNivel3;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ lblPuntaje1;
	private: System::Windows::Forms::Label^ lblPuntaje3;
	private: System::Windows::Forms::Label^ lblPuntaje2;
	private: System::Windows::Forms::Label^ lblPuntaje4;

		   BufferedGraphics^ buffer;
		   BufferedGraphics^ bufferStats;
		   GestorBiblioteca* gestor;
		   int finCont;
		   bool dialogoArchivo1 = false;
		   bool dialogoArchivo2 = false;
		   bool dialogoArchivo3 = false;
		   bool dialogoArchivo4 = false;
		   bool musicaSuspenso = false;
		   bool musicaFinal = false;
		   Point lblDerrotadosBase;
		   Point lblIntentosBase;
		   Point lblBateriaBase;
		   Point lblArchivo1Base;
		   Point lblArchivo2Base;
		   Point lblArchivo3Base;
		   Point lblArchivo4Base;
	       Point lblPuntaje1Base;
		   Point lblPuntaje2Base;
		   Point lblPuntaje3Base;
		   Point lblPuntaje4Base;
		   float mapa_escalaX = 1.0f;
		   float mapa_escalaY = 1.0f;
		   float stats_escalaX = 1.0f;
		   float stats_escalaY = 1.0f;
		   int puntajeFinal;
		   String^ nombre;


	private: System::Windows::Forms::Panel^ pnlEstadisticas;

	private:
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
			this->lblArchivo1 = (gcnew System::Windows::Forms::Label());
			this->lblArchivo2 = (gcnew System::Windows::Forms::Label());
			this->lblArchivo3 = (gcnew System::Windows::Forms::Label());
			this->lblArchivo4 = (gcnew System::Windows::Forms::Label());
			this->lblDerrotados = (gcnew System::Windows::Forms::Label());
			this->lblBateria = (gcnew System::Windows::Forms::Label());
			this->lblIntentos = (gcnew System::Windows::Forms::Label());
			this->tmrNivel3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblPuntaje1 = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje3 = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje2 = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje4 = (gcnew System::Windows::Forms::Label());
			this->pnlEstadisticas = (gcnew System::Windows::Forms::Panel());
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
			// lblArchivo1
			// 
			this->lblArchivo1->AutoSize = true;
			this->lblArchivo1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo1->Location = System::Drawing::Point(12, 506);
			this->lblArchivo1->Name = L"lblArchivo1";
			this->lblArchivo1->Size = System::Drawing::Size(52, 17);
			this->lblArchivo1->TabIndex = 13;
			this->lblArchivo1->Text = L"label1";
			// 
			// lblArchivo2
			// 
			this->lblArchivo2->AutoSize = true;
			this->lblArchivo2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo2->Location = System::Drawing::Point(178, 506);
			this->lblArchivo2->Name = L"lblArchivo2";
			this->lblArchivo2->Size = System::Drawing::Size(52, 17);
			this->lblArchivo2->TabIndex = 14;
			this->lblArchivo2->Text = L"label1";
			// 
			// lblArchivo3
			// 
			this->lblArchivo3->AutoSize = true;
			this->lblArchivo3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo3->Location = System::Drawing::Point(12, 577);
			this->lblArchivo3->Name = L"lblArchivo3";
			this->lblArchivo3->Size = System::Drawing::Size(52, 17);
			this->lblArchivo3->TabIndex = 15;
			this->lblArchivo3->Text = L"label1";
			// 
			// lblArchivo4
			// 
			this->lblArchivo4->AutoSize = true;
			this->lblArchivo4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo4->Location = System::Drawing::Point(178, 577);
			this->lblArchivo4->Name = L"lblArchivo4";
			this->lblArchivo4->Size = System::Drawing::Size(52, 17);
			this->lblArchivo4->TabIndex = 16;
			this->lblArchivo4->Text = L"label1";
			// 
			// lblDerrotados
			// 
			this->lblDerrotados->AutoSize = true;
			this->lblDerrotados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDerrotados->Location = System::Drawing::Point(12, 678);
			this->lblDerrotados->Name = L"lblDerrotados";
			this->lblDerrotados->Size = System::Drawing::Size(52, 17);
			this->lblDerrotados->TabIndex = 17;
			this->lblDerrotados->Text = L"label1";
			// 
			// lblBateria
			// 
			this->lblBateria->AutoSize = true;
			this->lblBateria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBateria->Location = System::Drawing::Point(12, 764);
			this->lblBateria->Name = L"lblBateria";
			this->lblBateria->Size = System::Drawing::Size(52, 17);
			this->lblBateria->TabIndex = 18;
			this->lblBateria->Text = L"label1";
			// 
			// lblIntentos
			// 
			this->lblIntentos->AutoSize = true;
			this->lblIntentos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIntentos->Location = System::Drawing::Point(12, 719);
			this->lblIntentos->Name = L"lblIntentos";
			this->lblIntentos->Size = System::Drawing::Size(52, 17);
			this->lblIntentos->TabIndex = 19;
			this->lblIntentos->Text = L"label1";
			// 
			// tmrNivel3
			// 
			this->tmrNivel3->Enabled = true;
			this->tmrNivel3->Interval = 16;
			this->tmrNivel3->Tick += gcnew System::EventHandler(this, &FrmNivel3::tmrNivel3_Tick);
			// 
			// lblPuntaje1
			// 
			this->lblPuntaje1->AutoSize = true;
			this->lblPuntaje1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje1->Location = System::Drawing::Point(12, 535);
			this->lblPuntaje1->Name = L"lblPuntaje1";
			this->lblPuntaje1->Size = System::Drawing::Size(52, 17);
			this->lblPuntaje1->TabIndex = 20;
			this->lblPuntaje1->Text = L"label1";
			// 
			// lblPuntaje3
			// 
			this->lblPuntaje3->AutoSize = true;
			this->lblPuntaje3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje3->Location = System::Drawing::Point(12, 608);
			this->lblPuntaje3->Name = L"lblPuntaje3";
			this->lblPuntaje3->Size = System::Drawing::Size(52, 17);
			this->lblPuntaje3->TabIndex = 21;
			this->lblPuntaje3->Text = L"label1";
			// 
			// lblPuntaje2
			// 
			this->lblPuntaje2->AutoSize = true;
			this->lblPuntaje2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje2->Location = System::Drawing::Point(178, 535);
			this->lblPuntaje2->Name = L"lblPuntaje2";
			this->lblPuntaje2->Size = System::Drawing::Size(52, 17);
			this->lblPuntaje2->TabIndex = 22;
			this->lblPuntaje2->Text = L"label1";
			// 
			// lblPuntaje4
			// 
			this->lblPuntaje4->AutoSize = true;
			this->lblPuntaje4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje4->Location = System::Drawing::Point(178, 608);
			this->lblPuntaje4->Name = L"lblPuntaje4";
			this->lblPuntaje4->Size = System::Drawing::Size(52, 17);
			this->lblPuntaje4->TabIndex = 23;
			this->lblPuntaje4->Text = L"label1";
			// 
			// pnlEstadisticas
			// 
			this->pnlEstadisticas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlEstadisticas->Controls->Add(this->lblPuntaje4);
			this->pnlEstadisticas->Controls->Add(this->lblBateria);
			this->pnlEstadisticas->Controls->Add(this->lblPuntaje2);
			this->pnlEstadisticas->Controls->Add(this->lblDerrotados);
			this->pnlEstadisticas->Controls->Add(this->lblPuntaje3);
			this->pnlEstadisticas->Controls->Add(this->lblPuntaje1);
			this->pnlEstadisticas->Controls->Add(this->lblIntentos);
			this->pnlEstadisticas->Controls->Add(this->lblArchivo4);
			this->pnlEstadisticas->Controls->Add(this->lblArchivo1);
			this->pnlEstadisticas->Controls->Add(this->lblArchivo3);
			this->pnlEstadisticas->Controls->Add(this->lblArchivo2);
			this->pnlEstadisticas->Location = System::Drawing::Point(1300, 0);
			this->pnlEstadisticas->Name = L"pnlEstadisticas";
			this->pnlEstadisticas->Size = System::Drawing::Size(300, 800);
			this->pnlEstadisticas->TabIndex = 24;
			// 
			// FrmNivel3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->pnlMapa);
			this->Controls->Add(this->pnlEstadisticas);
			this->Name = L"FrmNivel3";
			this->Text = L"Nivel 3: Biblioteca";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FrmNivel3::FrmNivel3_FormClosing);
			this->Load += gcnew System::EventHandler(this, &FrmNivel3::FrmNivel3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::FrmNivel3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::FrmNivel3_KeyUp);
			this->Resize += gcnew System::EventHandler(this, &FrmNivel3::FrmNivel3_Resize);
			this->pnlEstadisticas->ResumeLayout(false);
			this->pnlEstadisticas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	


private: System::Void FrmNivel3_Load(System::Object^ sender, System::EventArgs^ e) {
	gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);
	gestor->crearSprites();
	lblDerrotadosBase = lblDerrotados->Location;
	lblIntentosBase =	lblIntentos->Location;
	lblBateriaBase =	lblBateria->Location;

	lblArchivo1Base = lblArchivo1->Location;
	lblArchivo2Base = lblArchivo2->Location;
	lblArchivo3Base = lblArchivo3->Location;
	lblArchivo4Base = lblArchivo4->Location;

	lblPuntaje1Base = lblPuntaje1->Location;
	lblPuntaje2Base = lblPuntaje2->Location;
	lblPuntaje3Base = lblPuntaje3->Location;
	lblPuntaje4Base = lblPuntaje4->Location;
	//dialogo de inicio
	std::vector<std::string> frases;
	frases.push_back("(Radio) Reportera: ¡Oh no, parece que la banda criminal se ha inflitrado dentro del museo!");
	frases.push_back("(Radio) Reportera: Usa la tecla E para encender tu linterna y ahuyentar a los manipuladores. Puedes recargar tu linterna al acercarte al murcielago y presionar la tecla E.");
	frases.push_back("(Radio) Reportera: Si uno de los archivos es manipulado, se pierde parte de nuestra historia nacional...");
	frases.push_back("(Radio) Reportera: Si su puntaje desciende por debajo de 2000, la historia será manipulada. ¡Depende de ti preservar la historia del Perú!");
	gestor->getDialogo()->iniciar(frases);

	BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
	Graphics^ g = this->pnlMapa->CreateGraphics();
	buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
	tmrNivel3->Start();
	Recursos::normal3->PlayLooping();
	delete g;

	Graphics^ gStats = pnlEstadisticas->CreateGraphics();
	bufferStats = BufferedGraphicsManager::Current->Allocate(gStats, pnlEstadisticas->ClientRectangle);
	delete gStats;
}


private: System::Void FrmNivel3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (gestor->getDialogo()->estaActivo())
	{
		if (e->KeyCode == Keys::Space || e->KeyCode == Keys::Enter)
			gestor->getDialogo()->avanzar();
		e->Handled = true;
		return;
	}

	Guardia* g = gestor->getGuardia();
	if (e->KeyCode == Keys::Up) {
		g->setVelocidad(0, -6);
	}
	else if (e->KeyCode == Keys::Down) {
		g->setVelocidad(0, 6);
	}
	else if (e->KeyCode == Keys::Right) {
		g->setVelocidad(6, 0);
	}
	else if (e->KeyCode == Keys::Left) {
		g->setVelocidad(-6, 0);
	}
	//encender linterna
	else if (e->KeyCode == Keys::E) {
		g->setAccion(true);
		g->setTipoAccion(1);
	}
	//describir bienes
	else if (e->KeyCode == Keys::D) {
		g->setAccion(true);
		g->setTipoAccion(2);
	}
}
	Void PintarEstadisticas()
	{
	 Bitmap^ fondo = Recursos::PanelEstadisticas3;
	 bufferStats->Graphics->DrawImage(fondo, System::Drawing::Rectangle(0, 0, pnlEstadisticas->Width, pnlEstadisticas->Height));
	 gestor->dibujarDescripcion(bufferStats->Graphics);

	 Graphics^ g = pnlEstadisticas->CreateGraphics();
	 bufferStats->Render(g);
	 delete g;
	}
 Void Pintar(){

	 gestor->dibujar(buffer->Graphics);
	 gestor->getDialogo()->dibujar(buffer->Graphics, pnlMapa->ClientSize.Width, pnlMapa->ClientSize.Height);
	 Graphics^ g = this->pnlMapa->CreateGraphics();
	 buffer->Render(g);
	 delete g;
}
  private: System::Void FrmNivel3_Resize(System::Object^ sender, System::EventArgs^ e)
  {
	  if (buffer == nullptr)
		  return;
	  if (bufferStats == nullptr)
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
	  Graphics^ gStats = pnlEstadisticas->CreateGraphics();
	  bufferStats = contexto->Allocate(gStats, pnlEstadisticas->ClientRectangle);
	  delete gStats;
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
			 // ARCHIVOS
			 lblArchivo1->Location = Point(lblArchivo1Base.X * stats_escalaX, lblArchivo1Base.Y * stats_escalaY);
			 lblArchivo1->Font = fuente;
			 lblArchivo2->Location = Point(lblArchivo2Base.X * stats_escalaX, lblArchivo2Base.Y * stats_escalaY);
			 lblArchivo2->Font = fuente;
			 lblArchivo3->Location = Point(lblArchivo3Base.X * stats_escalaX, lblArchivo3Base.Y * stats_escalaY);
			 lblArchivo3->Font = fuente;
			 lblArchivo4->Location = Point(lblArchivo4Base.X * stats_escalaX, lblArchivo4Base.Y * stats_escalaY);
			 lblArchivo4->Font = fuente;
			 //PUNTAJES
			 lblPuntaje1->Location = Point(lblPuntaje1Base.X * stats_escalaX, lblPuntaje1Base.Y * stats_escalaY);
			 lblPuntaje1->Font = fuente;
			 lblPuntaje2->Location = Point(lblPuntaje2Base.X * stats_escalaX, lblPuntaje2Base.Y * stats_escalaY);
			 lblPuntaje2->Font = fuente;
			 lblPuntaje3->Location = Point(lblPuntaje3Base.X * stats_escalaX, lblPuntaje3Base.Y * stats_escalaY);
			 lblPuntaje3->Font = fuente;
			 lblPuntaje4->Location = Point(lblPuntaje4Base.X * stats_escalaX, lblPuntaje4Base.Y * stats_escalaY);
			 lblPuntaje4->Font = fuente;
			 // EXTRAS
			lblDerrotados->Location = Point(lblDerrotadosBase.X * stats_escalaX, lblDerrotadosBase.Y * stats_escalaY);
			lblDerrotados->Font = fuente;

			lblIntentos ->Location = Point(lblIntentosBase.X * stats_escalaX, lblIntentosBase.Y * stats_escalaY);
			lblIntentos->Font = fuente;

			lblBateria->Location = Point(lblBateriaBase.X * stats_escalaX, lblBateriaBase.Y * stats_escalaY);
			lblBateria->Font = fuente;

		 }
private: System::Void tmrNivel3_Tick(System::Object^ sender, System::EventArgs^ e) {

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
			this->tmrNivel3->Stop();
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

	if (!dialogoArchivo1 && gestor->getBien(0)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo1 = true;

		std::vector<std::string> archivo1;
		archivo1.push_back("El Archivo Caceres ha sido manipulado...");
		archivo1.push_back("Los documentos originales de Andres Avelino Caceres se han perdido.");
		archivo1.push_back("Con ellos desaparece parte de la memoria de la Guerra del Pacifico.");
		archivo1.push_back("¡No permitas que la historia del Peru sea borrada!");
		
		gestor->getDialogo()->iniciar(archivo1);
	}

	if (!dialogoArchivo2 && gestor->getBien(1)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo2 = true;

		std::vector<std::string> archivo2;
		archivo2.push_back("Las Tradiciones Peruanas han sido manipuladas...");
		archivo2.push_back("Las historias de Ricardo Palma ya no podran llegar a futuras generaciones.");
		archivo2.push_back("La identidad de un pueblo tambien vive en sus relatos.");
		archivo2.push_back("¡La cultura tambien necesita ser defendida!");

		gestor->getDialogo()->iniciar(archivo2);
	}
	//hOLA

	if (!dialogoArchivo3 && gestor->getBien(2)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo3 = true;

		std::vector<std::string> archivo3;
		archivo3.push_back("La Juramentacion de la Independencia ha sido manipulada...");
		archivo3.push_back("Los testimonios del nacimiento del Peru se han perdido.");
		archivo3.push_back("La libertad tambien se conserva en sus documentos.");
		archivo3.push_back("¡Protege el legado de nuestra independencia!");

		gestor->getDialogo()->iniciar(archivo3);
	}

	if (!dialogoArchivo4 && gestor->getBien(3)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo4 = true;

		std::vector<std::string> archivo4;
		archivo4.push_back("El Archivo Courret ha sido manipulado...");
		archivo4.push_back("Miles de fotografias historicas se han perdido para siempre.");
		archivo4.push_back("Sin ellas, una parte del Peru queda en el olvido.");
		archivo4.push_back("¡Cada fotografia es una ventana a nuestra historia!");

		gestor->getDialogo()->iniciar(archivo4);
	}

	if (!musicaSuspenso &&
		(gestor->getBien(0)->getPuntajeValor() <= 2000 || gestor->getBien(1)->getPuntajeValor() <= 2000 ||
		gestor->getBien(2)->getPuntajeValor() <= 2000 || gestor->getBien(3)->getPuntajeValor() <= 2000)) {

		musicaSuspenso = true;

		Recursos::normal3->Stop();
		Recursos::suspenso3->PlayLooping();
	}

	this->lblDerrotados->Text = String::Format(L"ENEMIGOS CAPTURADOS: {0}", (int)gestor->getCapturados());
	this->lblIntentos->Text = String::Format(L"VIDA: {0}", (int)gestor->getVidas());
	this->lblBateria->Text = String::Format("PORCENTAJE BATERIA: {0}%", (int)gestor->getPorcentajeLinterna());
	//archivos
	this->lblArchivo1->Text = gcnew System::String(gestor->getBien(0)->getNombre().c_str());
	this->lblArchivo2->Text = gcnew System::String(gestor->getBien(1)->getNombre().c_str());
	this->lblArchivo3->Text = gcnew System::String(gestor->getBien(2)->getNombre().c_str());
	this->lblArchivo4->Text = gcnew System::String(gestor->getBien(3)->getNombre().c_str());
	//puntajes
	this->lblPuntaje1->Text = String::Format("Puntaje: {0}", gestor->getBien(0)->getPuntajeValor());
	this->lblPuntaje2->Text = String::Format("Puntaje: {0}", gestor->getBien(1)->getPuntajeValor());
	this->lblPuntaje3->Text = String::Format("Puntaje: {0}", gestor->getBien(2)->getPuntajeValor());
	this->lblPuntaje4->Text = String::Format("Puntaje: {0}", gestor->getBien(3)->getPuntajeValor());

	if (gestor->victoria() || gestor->derrota())
	{
		if (gestor->victoria() && !musicaFinal) {
			Recursos::normal3->Stop();
			Recursos::suspenso3->Stop();
			Recursos::victoria->PlayLooping();
			musicaFinal = true;
		}
		if (gestor->derrota() && !musicaFinal) {
			Recursos::normal3->Stop();
			Recursos::suspenso3->Stop();
			Recursos::perdiste->PlayLooping();
			musicaFinal = true;
		}
		finCont++;
		if (finCont >= 200)
		{
			this->tmrNivel3->Stop();
			if (gestor->victoria())
			{
				IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(nombre);
				std::string nombreNormal(static_cast<const char*>(ptr.ToPointer()));
				System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
				Recursos::victoria->Stop();
				gestor->guardarPuntaje(gestor->getPuntaje() + puntajeFinal, nombreNormal);
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
			}
			if (gestor->derrota()) {
				IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(nombre);
				std::string nombreNormal(static_cast<const char*>(ptr.ToPointer()));
				System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
			Recursos::perdiste->Stop();
			gestor->guardarPuntaje(gestor->getPuntaje() + puntajeFinal, nombreNormal);
		}
			this->Close();
		}
	}

	if (!gestor->getDialogo()->estaActivo()) {
		gestor->jugar();
		gestor->detectarColisiones();
	}

	PintarEstadisticas();
	Pintar();
}

private: System::Void FrmNivel3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	Guardia* g = gestor->getGuardia();
	g->setVelocidad(0, 0);
	g->setAccion(false);
	g->setTipoAccion(0);
}

private: System::Void FrmNivel3_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	Recursos::normal3->Stop();
	Recursos::suspenso3->Stop();
	Recursos::victoria->Stop();
	Recursos::perdiste->Stop();
}
};
}
