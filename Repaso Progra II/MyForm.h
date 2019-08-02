#pragma once
#include "C_Encuesta.h"
#include "Form_PedirCantidad.h"
#include "Form_MostrarLista.h"

namespace PruebadeEntrada {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			Encuesta = new C_Encuesta();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label_PedirEdad;
	private: System::Windows::Forms::Label^  label_Titulo_Cuestionario;
	private: System::Windows::Forms::TextBox^  textBox_PedirEdad;
	private: System::Windows::Forms::Label^  label_PedirPreguntas;
	private: System::Windows::Forms::Label^  label_Pregunta1;
	private: C_Encuesta *Encuesta; int Indicador_Cuestionario = 0; bool sonDatosValidos=true;
	protected:


	protected:




	private: System::Windows::Forms::GroupBox^  groupBox_Pregunta1;
	private: System::Windows::Forms::RadioButton^  radioButton1_AlternativaC;

	private: System::Windows::Forms::RadioButton^  radioButton1_AlternativaB;
	private: System::Windows::Forms::RadioButton^  radioButton1_AlternativaD;




	private: System::Windows::Forms::RadioButton^  radioButton1_AlternativaA;





	private: System::Windows::Forms::GroupBox^  groupBox_ResultadosAnalisis;

	private: System::Windows::Forms::GroupBox^  groupBox_Pregunta2;
	private: System::Windows::Forms::RadioButton^  radioButton2_AlternativaC;


	private: System::Windows::Forms::RadioButton^  radioButton2_AlternativaB;
	private: System::Windows::Forms::RadioButton^  radioButton2_AlternativaD;


	private: System::Windows::Forms::RadioButton^  radioButton2_AlternativaA;

	private: System::Windows::Forms::Label^  label_Pregunta2;

	private: System::Windows::Forms::GroupBox^  groupBox_Pregunta3;
	private: System::Windows::Forms::RadioButton^  radioButton3_AlternativaC;


	private: System::Windows::Forms::RadioButton^  radioButton3_AlternativaB;
	private: System::Windows::Forms::RadioButton^  radioButton3_AlternativaD;


	private: System::Windows::Forms::RadioButton^  radioButton3_AlternativaA;

	private: System::Windows::Forms::Label^  label_Pregunta3;

	private: System::Windows::Forms::Button^  button_EnviarDatos;
	private: System::Windows::Forms::Label^  label_Resultado1;
	private: System::Windows::Forms::Label^  label_Resultado3;
	private: System::Windows::Forms::Label^  label_Resultado2;
	private: System::Windows::Forms::Button^  button_VerLista;


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
			this->label_PedirEdad = (gcnew System::Windows::Forms::Label());
			this->label_Titulo_Cuestionario = (gcnew System::Windows::Forms::Label());
			this->textBox_PedirEdad = (gcnew System::Windows::Forms::TextBox());
			this->label_PedirPreguntas = (gcnew System::Windows::Forms::Label());
			this->label_Pregunta1 = (gcnew System::Windows::Forms::Label());
			this->groupBox_Pregunta1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1_AlternativaC = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1_AlternativaB = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1_AlternativaD = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1_AlternativaA = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox_ResultadosAnalisis = (gcnew System::Windows::Forms::GroupBox());
			this->label_Resultado3 = (gcnew System::Windows::Forms::Label());
			this->label_Resultado2 = (gcnew System::Windows::Forms::Label());
			this->label_Resultado1 = (gcnew System::Windows::Forms::Label());
			this->groupBox_Pregunta2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2_AlternativaC = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2_AlternativaB = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2_AlternativaD = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2_AlternativaA = (gcnew System::Windows::Forms::RadioButton());
			this->label_Pregunta2 = (gcnew System::Windows::Forms::Label());
			this->groupBox_Pregunta3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3_AlternativaC = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3_AlternativaB = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3_AlternativaD = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3_AlternativaA = (gcnew System::Windows::Forms::RadioButton());
			this->label_Pregunta3 = (gcnew System::Windows::Forms::Label());
			this->button_EnviarDatos = (gcnew System::Windows::Forms::Button());
			this->button_VerLista = (gcnew System::Windows::Forms::Button());
			this->groupBox_Pregunta1->SuspendLayout();
			this->groupBox_ResultadosAnalisis->SuspendLayout();
			this->groupBox_Pregunta2->SuspendLayout();
			this->groupBox_Pregunta3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_PedirEdad
			// 
			this->label_PedirEdad->AutoSize = true;
			this->label_PedirEdad->Location = System::Drawing::Point(2, 37);
			this->label_PedirEdad->Name = L"label_PedirEdad";
			this->label_PedirEdad->Size = System::Drawing::Size(86, 13);
			this->label_PedirEdad->TabIndex = 0;
			this->label_PedirEdad->Text = L"Ingrese su edad:";
			// 
			// label_Titulo_Cuestionario
			// 
			this->label_Titulo_Cuestionario->AutoSize = true;
			this->label_Titulo_Cuestionario->Location = System::Drawing::Point(64, 9);
			this->label_Titulo_Cuestionario->Name = L"label_Titulo_Cuestionario";
			this->label_Titulo_Cuestionario->Size = System::Drawing::Size(99, 13);
			this->label_Titulo_Cuestionario->TabIndex = 1;
			this->label_Titulo_Cuestionario->Text = L"CUESTIONARIO N";
			// 
			// textBox_PedirEdad
			// 
			this->textBox_PedirEdad->Location = System::Drawing::Point(94, 37);
			this->textBox_PedirEdad->Name = L"textBox_PedirEdad";
			this->textBox_PedirEdad->Size = System::Drawing::Size(100, 20);
			this->textBox_PedirEdad->TabIndex = 2;
			// 
			// label_PedirPreguntas
			// 
			this->label_PedirPreguntas->AutoSize = true;
			this->label_PedirPreguntas->Location = System::Drawing::Point(22, 74);
			this->label_PedirPreguntas->Name = L"label_PedirPreguntas";
			this->label_PedirPreguntas->Size = System::Drawing::Size(172, 13);
			this->label_PedirPreguntas->TabIndex = 3;
			this->label_PedirPreguntas->Text = L"Responda las siguientes preguntas";
			// 
			// label_Pregunta1
			// 
			this->label_Pregunta1->AutoSize = true;
			this->label_Pregunta1->Location = System::Drawing::Point(6, 16);
			this->label_Pregunta1->Name = L"label_Pregunta1";
			this->label_Pregunta1->Size = System::Drawing::Size(218, 13);
			this->label_Pregunta1->TabIndex = 4;
			this->label_Pregunta1->Text = L"¿Recibe el salario adecuado por su trabajo\? ";
			// 
			// groupBox_Pregunta1
			// 
			this->groupBox_Pregunta1->Controls->Add(this->radioButton1_AlternativaC);
			this->groupBox_Pregunta1->Controls->Add(this->radioButton1_AlternativaB);
			this->groupBox_Pregunta1->Controls->Add(this->radioButton1_AlternativaD);
			this->groupBox_Pregunta1->Controls->Add(this->radioButton1_AlternativaA);
			this->groupBox_Pregunta1->Controls->Add(this->label_Pregunta1);
			this->groupBox_Pregunta1->Location = System::Drawing::Point(25, 101);
			this->groupBox_Pregunta1->Name = L"groupBox_Pregunta1";
			this->groupBox_Pregunta1->Size = System::Drawing::Size(299, 128);
			this->groupBox_Pregunta1->TabIndex = 5;
			this->groupBox_Pregunta1->TabStop = false;
			this->groupBox_Pregunta1->Text = L"Pregunta 1";
			// 
			// radioButton1_AlternativaC
			// 
			this->radioButton1_AlternativaC->AutoSize = true;
			this->radioButton1_AlternativaC->Location = System::Drawing::Point(25, 79);
			this->radioButton1_AlternativaC->Name = L"radioButton1_AlternativaC";
			this->radioButton1_AlternativaC->Size = System::Drawing::Size(39, 17);
			this->radioButton1_AlternativaC->TabIndex = 8;
			this->radioButton1_AlternativaC->TabStop = true;
			this->radioButton1_AlternativaC->Text = L"No";
			this->radioButton1_AlternativaC->UseVisualStyleBackColor = true;
			// 
			// radioButton1_AlternativaB
			// 
			this->radioButton1_AlternativaB->AutoSize = true;
			this->radioButton1_AlternativaB->Location = System::Drawing::Point(25, 55);
			this->radioButton1_AlternativaB->Name = L"radioButton1_AlternativaB";
			this->radioButton1_AlternativaB->Size = System::Drawing::Size(34, 17);
			this->radioButton1_AlternativaB->TabIndex = 7;
			this->radioButton1_AlternativaB->TabStop = true;
			this->radioButton1_AlternativaB->Text = L"Si";
			this->radioButton1_AlternativaB->UseVisualStyleBackColor = true;
			// 
			// radioButton1_AlternativaD
			// 
			this->radioButton1_AlternativaD->AutoSize = true;
			this->radioButton1_AlternativaD->Location = System::Drawing::Point(25, 99);
			this->radioButton1_AlternativaD->Name = L"radioButton1_AlternativaD";
			this->radioButton1_AlternativaD->Size = System::Drawing::Size(113, 17);
			this->radioButton1_AlternativaD->TabIndex = 6;
			this->radioButton1_AlternativaD->TabStop = true;
			this->radioButton1_AlternativaD->Text = L"Definitivamente no";
			this->radioButton1_AlternativaD->UseVisualStyleBackColor = true;
			// 
			// radioButton1_AlternativaA
			// 
			this->radioButton1_AlternativaA->AutoSize = true;
			this->radioButton1_AlternativaA->Location = System::Drawing::Point(25, 32);
			this->radioButton1_AlternativaA->Name = L"radioButton1_AlternativaA";
			this->radioButton1_AlternativaA->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->radioButton1_AlternativaA->Size = System::Drawing::Size(113, 17);
			this->radioButton1_AlternativaA->TabIndex = 5;
			this->radioButton1_AlternativaA->TabStop = true;
			this->radioButton1_AlternativaA->Text = L"Definitivamente sí ";
			this->radioButton1_AlternativaA->UseVisualStyleBackColor = true;
			// 
			// groupBox_ResultadosAnalisis
			// 
			this->groupBox_ResultadosAnalisis->Controls->Add(this->label_Resultado3);
			this->groupBox_ResultadosAnalisis->Controls->Add(this->label_Resultado2);
			this->groupBox_ResultadosAnalisis->Controls->Add(this->label_Resultado1);
			this->groupBox_ResultadosAnalisis->Location = System::Drawing::Point(25, 343);
			this->groupBox_ResultadosAnalisis->Name = L"groupBox_ResultadosAnalisis";
			this->groupBox_ResultadosAnalisis->Size = System::Drawing::Size(970, 172);
			this->groupBox_ResultadosAnalisis->TabIndex = 6;
			this->groupBox_ResultadosAnalisis->TabStop = false;
			this->groupBox_ResultadosAnalisis->Text = L"RESULTADOS DEL ANALISIS";
			// 
			// label_Resultado3
			// 
			this->label_Resultado3->AutoSize = true;
			this->label_Resultado3->Location = System::Drawing::Point(6, 128);
			this->label_Resultado3->Name = L"label_Resultado3";
			this->label_Resultado3->Size = System::Drawing::Size(464, 13);
			this->label_Resultado3->TabIndex = 2;
			this->label_Resultado3->Text = L"Cantidad de empleados que si reciben un salario adecuado y si están satisfechos c"
				L"on su empleo:";
			// 
			// label_Resultado2
			// 
			this->label_Resultado2->AutoSize = true;
			this->label_Resultado2->Location = System::Drawing::Point(6, 76);
			this->label_Resultado2->Name = L"label_Resultado2";
			this->label_Resultado2->Size = System::Drawing::Size(571, 13);
			this->label_Resultado2->TabIndex = 1;
			this->label_Resultado2->Text = L"Porcentaje de empleados que señalan que a menudo las tareas asignadas ayudan a de"
				L"sarrollar su aspecto profesional: ";
			// 
			// label_Resultado1
			// 
			this->label_Resultado1->AutoSize = true;
			this->label_Resultado1->Location = System::Drawing::Point(6, 31);
			this->label_Resultado1->Name = L"label_Resultado1";
			this->label_Resultado1->Size = System::Drawing::Size(493, 13);
			this->label_Resultado1->TabIndex = 0;
			this->label_Resultado1->Text = L"Cantidad de empleados que indican que definitivamente no reciben un salario adecu"
				L"ado por su trabajo:";
			// 
			// groupBox_Pregunta2
			// 
			this->groupBox_Pregunta2->Controls->Add(this->radioButton2_AlternativaC);
			this->groupBox_Pregunta2->Controls->Add(this->radioButton2_AlternativaB);
			this->groupBox_Pregunta2->Controls->Add(this->radioButton2_AlternativaD);
			this->groupBox_Pregunta2->Controls->Add(this->radioButton2_AlternativaA);
			this->groupBox_Pregunta2->Controls->Add(this->label_Pregunta2);
			this->groupBox_Pregunta2->Location = System::Drawing::Point(330, 101);
			this->groupBox_Pregunta2->Name = L"groupBox_Pregunta2";
			this->groupBox_Pregunta2->Size = System::Drawing::Size(360, 128);
			this->groupBox_Pregunta2->TabIndex = 9;
			this->groupBox_Pregunta2->TabStop = false;
			this->groupBox_Pregunta2->Text = L"Pregunta 2";
			// 
			// radioButton2_AlternativaC
			// 
			this->radioButton2_AlternativaC->AutoSize = true;
			this->radioButton2_AlternativaC->Location = System::Drawing::Point(25, 79);
			this->radioButton2_AlternativaC->Name = L"radioButton2_AlternativaC";
			this->radioButton2_AlternativaC->Size = System::Drawing::Size(80, 17);
			this->radioButton2_AlternativaC->TabIndex = 8;
			this->radioButton2_AlternativaC->TabStop = true;
			this->radioButton2_AlternativaC->Text = L"Raramente ";
			this->radioButton2_AlternativaC->UseVisualStyleBackColor = true;
			// 
			// radioButton2_AlternativaB
			// 
			this->radioButton2_AlternativaB->AutoSize = true;
			this->radioButton2_AlternativaB->Location = System::Drawing::Point(25, 55);
			this->radioButton2_AlternativaB->Name = L"radioButton2_AlternativaB";
			this->radioButton2_AlternativaB->Size = System::Drawing::Size(76, 17);
			this->radioButton2_AlternativaB->TabIndex = 7;
			this->radioButton2_AlternativaB->TabStop = true;
			this->radioButton2_AlternativaB->Text = L"A menudo ";
			this->radioButton2_AlternativaB->UseVisualStyleBackColor = true;
			// 
			// radioButton2_AlternativaD
			// 
			this->radioButton2_AlternativaD->AutoSize = true;
			this->radioButton2_AlternativaD->Location = System::Drawing::Point(25, 99);
			this->radioButton2_AlternativaD->Name = L"radioButton2_AlternativaD";
			this->radioButton2_AlternativaD->Size = System::Drawing::Size(60, 17);
			this->radioButton2_AlternativaD->TabIndex = 6;
			this->radioButton2_AlternativaD->TabStop = true;
			this->radioButton2_AlternativaD->Text = L"Nunca ";
			this->radioButton2_AlternativaD->UseVisualStyleBackColor = true;
			// 
			// radioButton2_AlternativaA
			// 
			this->radioButton2_AlternativaA->AutoSize = true;
			this->radioButton2_AlternativaA->Location = System::Drawing::Point(25, 32);
			this->radioButton2_AlternativaA->Name = L"radioButton2_AlternativaA";
			this->radioButton2_AlternativaA->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->radioButton2_AlternativaA->Size = System::Drawing::Size(98, 17);
			this->radioButton2_AlternativaA->TabIndex = 5;
			this->radioButton2_AlternativaA->TabStop = true;
			this->radioButton2_AlternativaA->Text = L"Muy a menudo ";
			this->radioButton2_AlternativaA->UseVisualStyleBackColor = true;
			// 
			// label_Pregunta2
			// 
			this->label_Pregunta2->AutoSize = true;
			this->label_Pregunta2->Location = System::Drawing::Point(6, 16);
			this->label_Pregunta2->Name = L"label_Pregunta2";
			this->label_Pregunta2->Size = System::Drawing::Size(329, 13);
			this->label_Pregunta2->TabIndex = 4;
			this->label_Pregunta2->Text = L"¿Las tareas asignadas ayudan a desarrollar su aspecto profesional\? ";
			// 
			// groupBox_Pregunta3
			// 
			this->groupBox_Pregunta3->Controls->Add(this->radioButton3_AlternativaC);
			this->groupBox_Pregunta3->Controls->Add(this->radioButton3_AlternativaB);
			this->groupBox_Pregunta3->Controls->Add(this->radioButton3_AlternativaD);
			this->groupBox_Pregunta3->Controls->Add(this->radioButton3_AlternativaA);
			this->groupBox_Pregunta3->Controls->Add(this->label_Pregunta3);
			this->groupBox_Pregunta3->Location = System::Drawing::Point(696, 101);
			this->groupBox_Pregunta3->Name = L"groupBox_Pregunta3";
			this->groupBox_Pregunta3->Size = System::Drawing::Size(299, 128);
			this->groupBox_Pregunta3->TabIndex = 9;
			this->groupBox_Pregunta3->TabStop = false;
			this->groupBox_Pregunta3->Text = L"Pregunta 3";
			// 
			// radioButton3_AlternativaC
			// 
			this->radioButton3_AlternativaC->AutoSize = true;
			this->radioButton3_AlternativaC->Location = System::Drawing::Point(25, 79);
			this->radioButton3_AlternativaC->Name = L"radioButton3_AlternativaC";
			this->radioButton3_AlternativaC->Size = System::Drawing::Size(39, 17);
			this->radioButton3_AlternativaC->TabIndex = 8;
			this->radioButton3_AlternativaC->TabStop = true;
			this->radioButton3_AlternativaC->Text = L"No";
			this->radioButton3_AlternativaC->UseVisualStyleBackColor = true;
			// 
			// radioButton3_AlternativaB
			// 
			this->radioButton3_AlternativaB->AutoSize = true;
			this->radioButton3_AlternativaB->Location = System::Drawing::Point(25, 55);
			this->radioButton3_AlternativaB->Name = L"radioButton3_AlternativaB";
			this->radioButton3_AlternativaB->Size = System::Drawing::Size(34, 17);
			this->radioButton3_AlternativaB->TabIndex = 7;
			this->radioButton3_AlternativaB->TabStop = true;
			this->radioButton3_AlternativaB->Text = L"Si";
			this->radioButton3_AlternativaB->UseVisualStyleBackColor = true;
			// 
			// radioButton3_AlternativaD
			// 
			this->radioButton3_AlternativaD->AutoSize = true;
			this->radioButton3_AlternativaD->Location = System::Drawing::Point(25, 99);
			this->radioButton3_AlternativaD->Name = L"radioButton3_AlternativaD";
			this->radioButton3_AlternativaD->Size = System::Drawing::Size(103, 17);
			this->radioButton3_AlternativaD->TabIndex = 6;
			this->radioButton3_AlternativaD->TabStop = true;
			this->radioButton3_AlternativaD->Text = L"No, en absoluto ";
			this->radioButton3_AlternativaD->UseVisualStyleBackColor = true;
			// 
			// radioButton3_AlternativaA
			// 
			this->radioButton3_AlternativaA->AutoSize = true;
			this->radioButton3_AlternativaA->Location = System::Drawing::Point(25, 32);
			this->radioButton3_AlternativaA->Name = L"radioButton3_AlternativaA";
			this->radioButton3_AlternativaA->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->radioButton3_AlternativaA->Size = System::Drawing::Size(77, 17);
			this->radioButton3_AlternativaA->TabIndex = 5;
			this->radioButton3_AlternativaA->TabStop = true;
			this->radioButton3_AlternativaA->Text = L"Sí, mucho ";
			this->radioButton3_AlternativaA->UseVisualStyleBackColor = true;
			// 
			// label_Pregunta3
			// 
			this->label_Pregunta3->AutoSize = true;
			this->label_Pregunta3->Location = System::Drawing::Point(6, 16);
			this->label_Pregunta3->Name = L"label_Pregunta3";
			this->label_Pregunta3->Size = System::Drawing::Size(166, 13);
			this->label_Pregunta3->TabIndex = 4;
			this->label_Pregunta3->Text = L"¿Está satisfecho con su empleo\? ";
			// 
			// button_EnviarDatos
			// 
			this->button_EnviarDatos->Location = System::Drawing::Point(450, 274);
			this->button_EnviarDatos->Name = L"button_EnviarDatos";
			this->button_EnviarDatos->Size = System::Drawing::Size(75, 23);
			this->button_EnviarDatos->TabIndex = 10;
			this->button_EnviarDatos->Text = L"ENVIAR";
			this->button_EnviarDatos->UseVisualStyleBackColor = true;
			this->button_EnviarDatos->Click += gcnew System::EventHandler(this, &MyForm::button_EnviarDatos_Click);
			// 
			// button_VerLista
			// 
			this->button_VerLista->Location = System::Drawing::Point(450, 521);
			this->button_VerLista->Name = L"button_VerLista";
			this->button_VerLista->Size = System::Drawing::Size(75, 23);
			this->button_VerLista->TabIndex = 11;
			this->button_VerLista->Text = L"VER LISTA";
			this->button_VerLista->UseVisualStyleBackColor = true;
			this->button_VerLista->Click += gcnew System::EventHandler(this, &MyForm::button_VerLista_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1009, 555);
			this->Controls->Add(this->button_VerLista);
			this->Controls->Add(this->button_EnviarDatos);
			this->Controls->Add(this->groupBox_Pregunta3);
			this->Controls->Add(this->groupBox_Pregunta2);
			this->Controls->Add(this->groupBox_ResultadosAnalisis);
			this->Controls->Add(this->groupBox_Pregunta1);
			this->Controls->Add(this->label_PedirPreguntas);
			this->Controls->Add(this->textBox_PedirEdad);
			this->Controls->Add(this->label_Titulo_Cuestionario);
			this->Controls->Add(this->label_PedirEdad);
			this->Name = L"MyForm";
			this->Text = L"ENCUESTA";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox_Pregunta1->ResumeLayout(false);
			this->groupBox_Pregunta1->PerformLayout();
			this->groupBox_ResultadosAnalisis->ResumeLayout(false);
			this->groupBox_ResultadosAnalisis->PerformLayout();
			this->groupBox_Pregunta2->ResumeLayout(false);
			this->groupBox_Pregunta2->PerformLayout();
			this->groupBox_Pregunta3->ResumeLayout(false);
			this->groupBox_Pregunta3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		label_Titulo_Cuestionario->Text = "Cuestionario 1";

		Form_PedirCantidad ^Formulario_PedirCantidad = gcnew Form_PedirCantidad(); //Creo el cuestionario para pedir cantidad de encuestas

		Formulario_PedirCantidad->ShowDialog(); //Lo muestro como cuadro de dialogo

		Encuesta->setEncuesta(Formulario_PedirCantidad->getCantidadEncuestas());//Obtengo el valor ingresado y lo paso al objeto

	}
private: System::Void button_EnviarDatos_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Indicador_Cuestionario < Encuesta->getNumero_Cuestionarios()) { //Compruebo que aun no lleno todos los cuestionarios
		
		if (Encuesta->getEncuesta()[Indicador_Cuestionario].setEdad(Convert::ToInt32(textBox_PedirEdad->Text))) {//Recibo la edad 
			//y veo si cumple lo necesario

			sonDatosValidos = true;

			Encuesta->getEncuesta()[Indicador_Cuestionario].setIndice(Indicador_Cuestionario + 1); //Le indico su numero al cuestionario

			////////////////////////////VERIFICO ALTERNATIVAS EN LAS PREGUNTAS//////////
		///////////////////////////////////////////////////////////////////////////
		//////Pregunta 1
			if (radioButton1_AlternativaA->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta1('A');
			}
			else if (radioButton1_AlternativaB->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta1('B');
			}
			else if (radioButton1_AlternativaC->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta1('C');
			}
			else if (radioButton1_AlternativaD->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta1('D');
			}
			else {
				sonDatosValidos = false;
			}

			//////Pregunta 2
			if (radioButton2_AlternativaA->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta2('A');
			}
			else if (radioButton2_AlternativaB->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta2('B');
			}
			else if (radioButton2_AlternativaC->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta2('C');
			}
			else if (radioButton2_AlternativaD->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta2('D');
			}
			else {
				sonDatosValidos = false;
			}

			//////Pregunta 3
			if (radioButton3_AlternativaA->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta3('A');
			}
			else if (radioButton3_AlternativaB->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta3('B');
			}
			else if (radioButton3_AlternativaC->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta3('C');
			}
			else if (radioButton3_AlternativaD->Checked) {
				Encuesta->getEncuesta()[Indicador_Cuestionario].setRespuesta3('D');
			}
			else {
				sonDatosValidos = false;
			}




			//Ingreso datos y paso al siguiente cuestionario
			if (sonDatosValidos) {
				Indicador_Cuestionario += 1;
				label_Titulo_Cuestionario->Text = "Cuestionario " + (Indicador_Cuestionario + 1);



				//Limpiar entradas y alternativas
				textBox_PedirEdad->Clear();

				radioButton1_AlternativaA->Checked = false;
				radioButton1_AlternativaB->Checked = false;
				radioButton1_AlternativaC->Checked = false;
				radioButton1_AlternativaD->Checked = false;


				radioButton2_AlternativaA->Checked = false;
				radioButton2_AlternativaB->Checked = false;
				radioButton2_AlternativaC->Checked = false;
				radioButton2_AlternativaD->Checked = false;


				radioButton3_AlternativaA->Checked = false;
				radioButton3_AlternativaB->Checked = false;
				radioButton3_AlternativaC->Checked = false;
				radioButton3_AlternativaD->Checked = false;

				if (Indicador_Cuestionario == Encuesta->getNumero_Cuestionarios()) {
					label_Titulo_Cuestionario->Text = "Todos los cuestionarios registrados";
					Encuesta->Analizar_Datos();
					label_Resultado1->Text = "Cantidad de empleados que indican que definitivamente no reciben un salario adecuado por su trabajo: " + Encuesta->getCE_Tipo1();
					label_Resultado2->Text = "Porcentaje de empleados que señalan que a menudo las tareas asignadas ayudan a desarrollar su aspecto profesional: " + (float(Encuesta->getCE_Tipo2()) / Encuesta->getNumero_Cuestionarios() * 100) + " %";
					label_Resultado3->Text = "Cantidad de empleados que si reciben un salario adecuado y si están satisfechos con su empleo: " + Encuesta->getCE_Tipo3();
				}
			}

			
		}
		else {
			//Limpiar entradas
			textBox_PedirEdad->Clear();

			radioButton1_AlternativaA->Checked = false;
			radioButton1_AlternativaB->Checked = false;
			radioButton1_AlternativaC->Checked = false;
			radioButton1_AlternativaD->Checked = false;


			radioButton2_AlternativaA->Checked = false;
			radioButton2_AlternativaB->Checked = false;
			radioButton2_AlternativaC->Checked = false;
			radioButton2_AlternativaD->Checked = false;


			radioButton3_AlternativaA->Checked = false;
			radioButton3_AlternativaB->Checked = false;
			radioButton3_AlternativaC->Checked = false;
			radioButton3_AlternativaD->Checked = false;

			MessageBox::Show("INGRESE DATOS VALIDOS");
		}


		

	}
	else {
	//Limpiar entradas y alternativas
	textBox_PedirEdad->Clear();

	radioButton1_AlternativaA->Checked = false;
	radioButton1_AlternativaB->Checked = false;
	radioButton1_AlternativaC->Checked = false;
	radioButton1_AlternativaD->Checked = false;


	radioButton2_AlternativaA->Checked = false;
	radioButton2_AlternativaB->Checked = false;
	radioButton2_AlternativaC->Checked = false;
	radioButton2_AlternativaD->Checked = false;


	radioButton3_AlternativaA->Checked = false;
	radioButton3_AlternativaB->Checked = false;
	radioButton3_AlternativaC->Checked = false;
	radioButton3_AlternativaD->Checked = false;
	}
}

////Falta mostrar otro formulario donde se muestre en orden los datos

private: System::Void button_VerLista_Click(System::Object^  sender, System::EventArgs^  e) {
	Encuesta->Ordenar_Datos();

	Form_MostrarLista ^Formulario_ListaOrdenada = gcnew Form_MostrarLista();

	Formulario_ListaOrdenada->Actualizar_Lista(*Encuesta);

	Formulario_ListaOrdenada->ShowDialog();

}
};
}
