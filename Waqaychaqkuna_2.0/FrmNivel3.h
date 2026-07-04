#pragma once
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
		FrmNivel3(void)
		{
			gestor = new GestorBiblioteca(30);
			InitializeComponent();
			finCont = 0;
			//
			//TODO: agregar código de constructor aquí
			//
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
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ lblArchivo1;
	private: System::Windows::Forms::Label^ lblArchivo2;
	private: System::Windows::Forms::Label^ lblArchivo3;
	private: System::Windows::Forms::Label^ lblArchivo4;
	private: System::Windows::Forms::Label^ lblDerrotados;
	private: System::Windows::Forms::Label^ lblBateria;
	private: System::Windows::Forms::Label^ lblIntentos;
	private: System::Windows::Forms::Timer^ tmrNivel3;
	private: System::ComponentModel::IContainer^ components;
	 BufferedGraphics^ buffer;
	private: System::Windows::Forms::Label^ lblPuntaje1;
	private: System::Windows::Forms::Label^ lblPuntaje3;
	private: System::Windows::Forms::Label^ lblPuntaje2;
	private: System::Windows::Forms::Label^ lblPuntaje4;

		   GestorBiblioteca* gestor;
		   int finCont;

		   bool dialogoArchivo1 = false;
		   bool dialogoArchivo2 = false;
		   bool dialogoArchivo3 = false;
		   bool dialogoArchivo4 = false;
		   bool musicaSuspenso = false;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(1311, 139);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(199, 40);
			this->label1->TabIndex = 11;
			this->label1->Text = L"\'E\' PARA\r\nENCENDER LINTERNA";
			// 
			// lblArchivo1
			// 
			this->lblArchivo1->AutoSize = true;
			this->lblArchivo1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo1->Location = System::Drawing::Point(1312, 316);
			this->lblArchivo1->Name = L"lblArchivo1";
			this->lblArchivo1->Size = System::Drawing::Size(95, 17);
			this->lblArchivo1->TabIndex = 13;

			// 
			// lblArchivo2
			// 
			this->lblArchivo2->AutoSize = true;
			this->lblArchivo2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo2->Location = System::Drawing::Point(1478, 316);
			this->lblArchivo2->Name = L"lblArchivo2";
			this->lblArchivo2->Size = System::Drawing::Size(95, 17);
			this->lblArchivo2->TabIndex = 14;

			// 
			// lblArchivo3
			// 
			this->lblArchivo3->AutoSize = true;
			this->lblArchivo3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo3->Location = System::Drawing::Point(1312, 387);
			this->lblArchivo3->Name = L"lblArchivo3";
			this->lblArchivo3->Size = System::Drawing::Size(95, 17);
			this->lblArchivo3->TabIndex = 15;

			// 
			// lblArchivo4
			// 
			this->lblArchivo4->AutoSize = true;
			this->lblArchivo4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblArchivo4->Location = System::Drawing::Point(1478, 387);
			this->lblArchivo4->Name = L"lblArchivo4";
			this->lblArchivo4->Size = System::Drawing::Size(95, 17);
			this->lblArchivo4->TabIndex = 16;

			// 
			// lblDerrotados
			// 
			this->lblDerrotados->AutoSize = true;
			this->lblDerrotados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDerrotados->Location = System::Drawing::Point(1319, 648);
			this->lblDerrotados->Name = L"lblDerrotados";
			this->lblDerrotados->Size = System::Drawing::Size(221, 17);
			this->lblDerrotados->TabIndex = 17;

			// 
			// lblBateria
			// 
			this->lblBateria->AutoSize = true;
			this->lblBateria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBateria->Location = System::Drawing::Point(1319, 734);
			this->lblBateria->Name = L"lblBateria";
			this->lblBateria->Size = System::Drawing::Size(0, 17);
			this->lblBateria->TabIndex = 18;
			// 
			// lblIntentos
			// 
			this->lblIntentos->AutoSize = true;
			this->lblIntentos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIntentos->Location = System::Drawing::Point(1319, 694);
			this->lblIntentos->Name = L"lblIntentos";
			this->lblIntentos->Size = System::Drawing::Size(105, 17);
			this->lblIntentos->TabIndex = 19;

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
			this->lblPuntaje1->Location = System::Drawing::Point(1312, 345);
			this->lblPuntaje1->Name = L"lblPuntaje1";
			this->lblPuntaje1->Size = System::Drawing::Size(17, 17);
			this->lblPuntaje1->TabIndex = 20;

			// 
			// lblPuntaje3
			// 
			this->lblPuntaje3->AutoSize = true;
			this->lblPuntaje3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje3->Location = System::Drawing::Point(1312, 418);
			this->lblPuntaje3->Name = L"lblPuntaje3";
			this->lblPuntaje3->Size = System::Drawing::Size(17, 17);
			this->lblPuntaje3->TabIndex = 21;

			// 
			// lblPuntaje2
			// 
			this->lblPuntaje2->AutoSize = true;
			this->lblPuntaje2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje2->Location = System::Drawing::Point(1478, 345);
			this->lblPuntaje2->Name = L"lblPuntaje2";
			this->lblPuntaje2->Size = System::Drawing::Size(17, 17);
			this->lblPuntaje2->TabIndex = 22;

			// 
			// lblPuntaje4
			// 
			this->lblPuntaje4->AutoSize = true;
			this->lblPuntaje4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje4->Location = System::Drawing::Point(1478, 418);
			this->lblPuntaje4->Name = L"lblPuntaje4";
			this->lblPuntaje4->Size = System::Drawing::Size(17, 17);
			this->lblPuntaje4->TabIndex = 23;

			// 
			// FrmNivel3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 800);
			this->Controls->Add(this->lblPuntaje4);
			this->Controls->Add(this->lblPuntaje2);
			this->Controls->Add(this->lblPuntaje3);
			this->Controls->Add(this->lblPuntaje1);
			this->Controls->Add(this->lblIntentos);
			this->Controls->Add(this->lblBateria);
			this->Controls->Add(this->lblDerrotados);
			this->Controls->Add(this->lblArchivo4);
			this->Controls->Add(this->lblArchivo3);
			this->Controls->Add(this->lblArchivo2);
			this->Controls->Add(this->lblArchivo1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pnlMapa);
			this->Name = L"FrmNivel3";
			this->Text = L"Nivel 3: Biblioteca";
			this->Load += gcnew System::EventHandler(this, &FrmNivel3::FrmNivel3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::FrmNivel3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNivel3::FrmNivel3_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	


private: System::Void FrmNivel3_Load(System::Object^ sender, System::EventArgs^ e) {
	gestor->setLienzo(this->pnlMapa->Width, this->pnlMapa->Height);
	gestor->crearSprites();

	//dialogo de inicio
	std::vector<std::string> frases;
	frases.push_back("(Radio) Reportera: ¡Oh no, parece que la banda criminal se ha inflitrado dentro del museo!");
	frases.push_back("(Radio) Reportera: Usa la tecla E para encender tu linterna y ahuyentar a los manipuladores. Puedes recargar tu linterna al acercarte al murcielago y presionar la tecla R.");
	frases.push_back("(Radio) Reportera: Cada archivo contiene acontecimientos historicos importantes en la historia del Perú. Si uno es manipulado, se pierde parte de nuestra historia nacional.");
	frases.push_back("(Radio) Reportera: Si su desciende por debajo de 2000, la historia será manipulada. ¡Depende de ti preservar la historia del Perú!");
	gestor->getDialogo()->iniciar(frases);

	BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
	Graphics^ g = this->pnlMapa->CreateGraphics();
	buffer = contexto->Allocate(g, this->pnlMapa->ClientRectangle);
	tmrNivel3->Start();
	Recursos::normal3->PlayLooping();
	delete g;
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

 Void Pintar(){

	 gestor->dibujar(buffer->Graphics);
	 gestor->getDialogo()->dibujar(buffer->Graphics, pnlMapa->ClientSize.Width, pnlMapa->ClientSize.Height);
	 Graphics^ g = this->pnlMapa->CreateGraphics();
	 buffer->Render(g);
	 delete g;
}

private: System::Void tmrNivel3_Tick(System::Object^ sender, System::EventArgs^ e) {

	gestor->getDialogo()->actualizar();
	if (gestor->victoria())
	{
		finCont++;
		if (finCont >= 120)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	if (!dialogoArchivo1 && gestor->getBien(0)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo1 = true;

		std::vector<std::string> archivo1;
		archivo1.push_back("La Huaca del Sol ha sido destruida...");
		archivo1.push_back("Fue el mayor centro ceremonial de la cultura Moche.");
		archivo1.push_back("Con ella se pierde parte de la historia y arquitectura del Perú.");
		archivo1.push_back("¡Protege nuestro patrimonio antes de que sea demasiado tarde!");

		gestor->getDialogo()->iniciar(archivo1);
	}

	if (!dialogoArchivo2 && gestor->getBien(1)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo2 = true;

		std::vector<std::string> archivo2;
		archivo2.push_back("La Huaca de la Luna ha sido destruida...");
		archivo2.push_back("Sus murales narraban rituales y creencias de los mochicas.");
		archivo2.push_back("Cada pintura perdida borra parte de nuestra memoria cultural.");
		archivo2.push_back("¡No permitas que el huaqueo destruya nuestra historia!");

		gestor->getDialogo()->iniciar(archivo2);
	}
	//hOLA

	if (!dialogoArchivo3 && gestor->getBien(2)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo3 = true;

		std::vector<std::string> archivo3;
		archivo3.push_back("La Huaca Dragón ha sido destruida...");
		archivo3.push_back("Sus relieves representaban importantes símbolos de la cultura Chimú.");
		archivo3.push_back("Su destrucción significa perder valiosa evidencia arqueológica.");
		archivo3.push_back("¡El patrimonio cultural necesita ser protegido por todos!");

		gestor->getDialogo()->iniciar(archivo3);
	}

	if (!dialogoArchivo4 && gestor->getBien(3)->getPuntajeValor() <= 2000)
	{
		dialogoArchivo4 = true;

		std::vector<std::string> archivo4;
		archivo4.push_back("La Huaca Takaynamo ha sido destruida...");
		archivo4.push_back("Está vinculada al origen legendario del reino Chimú.");
		archivo4.push_back("Cada monumento perdido debilita nuestra identidad cultural.");
		archivo4.push_back("¡Conservar el patrimonio es preservar nuestra historia!");

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
	this->lblBateria->Text = String::Format("PORCENTAJE BATERIA: {0}", (int)gestor->getTiempoRecarga());
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

	if (!gestor->getDialogo()->estaActivo()) {
		gestor->jugar();
		gestor->detectarColisiones();
	}

	Pintar();

	if (gestor->victoria())
	{
		this->tmrNivel3->Stop();
		Recursos::suspenso2->Stop();
		MessageBox::Show("GANASTE");
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	if (gestor->derrota())
	{
		Recursos::suspenso2->Stop();
		this->tmrNivel3->Stop();
		MessageBox::Show("PERDISTE");
		this->Close();
	}
}

private: System::Void FrmNivel3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	Guardia* g = gestor->getGuardia();
	g->setVelocidad(0, 0);
	g->setAccion(false);
	g->setTipoAccion(0);
}

};
}
