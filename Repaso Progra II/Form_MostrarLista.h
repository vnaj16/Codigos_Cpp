#pragma once
#include "C_Encuesta.h"

namespace PruebadeEntrada {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_MostrarLista
	/// </summary>
	public ref class Form_MostrarLista : public System::Windows::Forms::Form
	{
	public:
		Form_MostrarLista(void)
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
		~Form_MostrarLista()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox_MostrarDatos;
	protected:

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
			this->listBox_MostrarDatos = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox_MostrarDatos
			// 
			this->listBox_MostrarDatos->FormattingEnabled = true;
			this->listBox_MostrarDatos->Location = System::Drawing::Point(12, 12);
			this->listBox_MostrarDatos->Name = L"listBox_MostrarDatos";
			this->listBox_MostrarDatos->Size = System::Drawing::Size(348, 147);
			this->listBox_MostrarDatos->TabIndex = 0;
			// 
			// Form_MostrarLista
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(372, 182);
			this->Controls->Add(this->listBox_MostrarDatos);
			this->Name = L"Form_MostrarLista";
			this->Text = L"Lista Ordenada";
			this->Load += gcnew System::EventHandler(this, &Form_MostrarLista::Form_MostrarLista_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void Actualizar_Lista(C_Encuesta &Encuesta) {
		for (int i = 0; i < Encuesta.getNumero_Cuestionarios(); i++) {
			listBox_MostrarDatos->Items->Add("Empleado " + Encuesta.getEncuesta()[i].getIndice()
				+ "  Edad: " + Encuesta.getEncuesta()[i].getEdad());
		}
	}
	private: System::Void Form_MostrarLista_Load(System::Object^  sender, System::EventArgs^  e) {
	
	}
	};
}
