#pragma once


namespace PruebadeEntrada {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_PedirEdad
	/// </summary>
	public ref class Form_PedirCantidad : public System::Windows::Forms::Form
	{
	public:
		Form_PedirCantidad(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form_PedirCantidad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label_PedirCantidad;
			 int Numero_Encuestas = 0;
	private: System::Windows::Forms::TextBox^  textBox_PedirCantidad;
	private: System::Windows::Forms::Button^  button_EnviarCantidad;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label_PedirCantidad = (gcnew System::Windows::Forms::Label());
			this->textBox_PedirCantidad = (gcnew System::Windows::Forms::TextBox());
			this->button_EnviarCantidad = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_PedirCantidad
			// 
			this->label_PedirCantidad->AutoSize = true;
			this->label_PedirCantidad->Location = System::Drawing::Point(138, 9);
			this->label_PedirCantidad->Name = L"label_PedirCantidad";
			this->label_PedirCantidad->Size = System::Drawing::Size(194, 13);
			this->label_PedirCantidad->TabIndex = 0;
			this->label_PedirCantidad->Text = L"Ingrese el numero de encuestas (1-100)";
			// 
			// textBox_PedirCantidad
			// 
			this->textBox_PedirCantidad->Location = System::Drawing::Point(179, 37);
			this->textBox_PedirCantidad->Name = L"textBox_PedirCantidad";
			this->textBox_PedirCantidad->Size = System::Drawing::Size(100, 20);
			this->textBox_PedirCantidad->TabIndex = 1;
			// 
			// button_EnviarCantidad
			// 
			this->button_EnviarCantidad->Location = System::Drawing::Point(191, 63);
			this->button_EnviarCantidad->Name = L"button_EnviarCantidad";
			this->button_EnviarCantidad->Size = System::Drawing::Size(75, 23);
			this->button_EnviarCantidad->TabIndex = 2;
			this->button_EnviarCantidad->Text = L"Enviar";
			this->button_EnviarCantidad->UseVisualStyleBackColor = true;
			this->button_EnviarCantidad->Click += gcnew System::EventHandler(this, &Form_PedirCantidad::button_EnviarCantidad_Click);
			// 
			// Form_PedirCantidad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(471, 110);
			this->Controls->Add(this->button_EnviarCantidad);
			this->Controls->Add(this->textBox_PedirCantidad);
			this->Controls->Add(this->label_PedirCantidad);
			this->Name = L"Form_PedirCantidad";
			this->Text = L"INGRESAR CANTIDAD";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: int getCantidadEncuestas() {
		return Numero_Encuestas;
	}

	private: System::Void button_EnviarCantidad_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Convert::ToInt32(textBox_PedirCantidad->Text) >= 1 && Convert::ToInt32(textBox_PedirCantidad->Text) <= 100) {
			Numero_Encuestas = Convert::ToInt32(textBox_PedirCantidad->Text);
			this->Close();
		}
		else {
			textBox_PedirCantidad->Clear();
			MessageBox::Show("INGRESE DATOS VALIDOS");
		}
	}
	};
}
