#pragma once

namespace Waqaychaqkuna20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmSlodVictoria
	/// </summary>
	public ref class FrmSlodVictoria : public System::Windows::Forms::Form
	{
	public:
		FrmSlodVictoria(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmSlodVictoria()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmSlodVictoria::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(1166, 750);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(425, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Presiona ENTER para continuar...";
			// 
			// FrmSlodVictoria
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1603, 800);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"FrmSlodVictoria";
			this->Text = L"FrmSlodVictoria";
			this->Load += gcnew System::EventHandler(this, &FrmSlodVictoria::FrmSlodVictoria_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmSlodVictoria::FrmSlodVictoria_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &FrmSlodVictoria::FrmSlodVictoria_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmSlodVictoria_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void FrmSlodVictoria_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		if (e->KeyCode == Keys::Enter)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}
	private: System::Void FrmSlodVictoria_Resize(System::Object^ sender, System::EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();
		g->Clear(Color::Transparent);
		g->DrawImage(gcnew Bitmap("backgrounds\\slod7.png"), System::Drawing::Rectangle(0, 0, this->ClientSize.Width, this->ClientSize.Height), System::Drawing::Rectangle(0, 0, 940, 530), GraphicsUnit::Pixel);
		delete g;
		this->label1->Left = this->ClientSize.Width - this->label1->Width - 30;
		this->label1->Top = this->ClientSize.Height - this->label1->Height - 30;
	}
	};
}
