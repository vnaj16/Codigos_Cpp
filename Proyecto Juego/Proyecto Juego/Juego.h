#pragma once
#include "C_Personaje.h"
#include "C_Disco.h"
#include "C_Mapa.h"
#include "C_Nivel.h"
#include "C_Minijuego.h"
namespace ProyectoJuego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Hito2
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		Juego(void)
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
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		////Contadores para simular tiempo
		int contadorML = 0, contadorT = 0, contadorD = 0, Tiempo_Nuevo_Disco = 30, Posicion_X_Banner = 5;
		int Posicion_X_Menu = 150, Posicion_Y_Menu = 80, Movimiento_X_Menu = 25;
		int Iterador_Bomba=0;
		Random ^r;
		bool Level1 = true, Level2 = false, Level3 = false, Level4 = false, Level5 = false, Ganar = false, Perder = false;
		/////Niveles
		C_Nivel *Nivel1;
		C_Nivel *Nivel2;
		C_Nivel *Nivel3;
		C_Nivel *Nivel4;
		C_Nivel *Nivel5;

		/////Personaje
		C_Personaje *Personaje;


		C_Minijuego *Minijuego;

		/////Imagenes
		Bitmap ^bmpPersonaje = gcnew Bitmap("Mario.png");
		Bitmap ^bmpPersonajeX = gcnew Bitmap("MarioX.png");
		Bitmap ^bmpDisco = gcnew Bitmap("SierraCircular.png");
		Bitmap ^bmpDiscoX = gcnew Bitmap("SierraCircularX.png");
		Bitmap ^Map;
		Bitmap ^bmpMario_Menu = gcnew Bitmap("FondoMenuMario.jpg");

		Bitmap ^bmpBomba = gcnew Bitmap("Bomba.png");


		////Fuente para escribir datos
		Drawing::Font ^Fuente = gcnew Drawing::Font("Bauhaus 93", 15);
		Drawing::Font ^Fuente_Menu = gcnew Drawing::Font("Bauhaus 93", 30);


	private: System::Windows::Forms::Timer^  timer_Niveles;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer_Banners;
	private: System::Windows::Forms::Timer^  timer_Menu;
	private: System::Windows::Forms::Button^  button_Jugar;
	private: System::Windows::Forms::Button^  button_Creditos;
	private: System::Windows::Forms::Button^  button_Salir;
	private: System::Windows::Forms::Timer^  timer_Creditos;
	private: System::Windows::Forms::Button^  button_Minijuego;
	private: System::Windows::Forms::Timer^  timer_Minijuego;

	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Método necesario para admitir el Diseñador. No se puede modificar
			 /// el contenido de este método con el editor de código.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
				 this->timer_Niveles = (gcnew System::Windows::Forms::Timer(this->components));
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->timer_Banners = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer_Menu = (gcnew System::Windows::Forms::Timer(this->components));
				 this->button_Jugar = (gcnew System::Windows::Forms::Button());
				 this->button_Creditos = (gcnew System::Windows::Forms::Button());
				 this->button_Salir = (gcnew System::Windows::Forms::Button());
				 this->timer_Creditos = (gcnew System::Windows::Forms::Timer(this->components));
				 this->button_Minijuego = (gcnew System::Windows::Forms::Button());
				 this->timer_Minijuego = (gcnew System::Windows::Forms::Timer(this->components));
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // timer_Niveles
				 // 
				 this->timer_Niveles->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(12, 33);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(108, 89);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Visible = false;
				 // 
				 // timer_Banners
				 // 
				 this->timer_Banners->Tick += gcnew System::EventHandler(this, &Juego::timer_Banners_Tick);
				 // 
				 // timer_Menu
				 // 
				 this->timer_Menu->Enabled = true;
				 this->timer_Menu->Tick += gcnew System::EventHandler(this, &Juego::timer_Menu_Tick);
				 // 
				 // button_Jugar
				 // 
				 this->button_Jugar->Location = System::Drawing::Point(318, 255);
				 this->button_Jugar->Name = L"button_Jugar";
				 this->button_Jugar->Size = System::Drawing::Size(75, 23);
				 this->button_Jugar->TabIndex = 1;
				 this->button_Jugar->Text = L"JUGAR";
				 this->button_Jugar->UseVisualStyleBackColor = true;
				 this->button_Jugar->Visible = false;
				 this->button_Jugar->Click += gcnew System::EventHandler(this, &Juego::button_Jugar_Click);
				 // 
				 // button_Creditos
				 // 
				 this->button_Creditos->Location = System::Drawing::Point(318, 320);
				 this->button_Creditos->Name = L"button_Creditos";
				 this->button_Creditos->Size = System::Drawing::Size(75, 23);
				 this->button_Creditos->TabIndex = 2;
				 this->button_Creditos->Text = L"CREDITOS";
				 this->button_Creditos->UseVisualStyleBackColor = true;
				 this->button_Creditos->Visible = false;
				 this->button_Creditos->Click += gcnew System::EventHandler(this, &Juego::button_Creditos_Click);
				 // 
				 // button_Salir
				 // 
				 this->button_Salir->Location = System::Drawing::Point(318, 440);
				 this->button_Salir->Name = L"button_Salir";
				 this->button_Salir->Size = System::Drawing::Size(75, 23);
				 this->button_Salir->TabIndex = 3;
				 this->button_Salir->Text = L"SALIR";
				 this->button_Salir->UseVisualStyleBackColor = true;
				 this->button_Salir->Visible = false;
				 this->button_Salir->Click += gcnew System::EventHandler(this, &Juego::button_Salir_Click);
				 // 
				 // timer_Creditos
				 // 
				 this->timer_Creditos->Tick += gcnew System::EventHandler(this, &Juego::timer_Creditos_Tick);
				 // 
				 // button_Minijuego
				 // 
				 this->button_Minijuego->Location = System::Drawing::Point(256, 380);
				 this->button_Minijuego->Name = L"button_Minijuego";
				 this->button_Minijuego->Size = System::Drawing::Size(199, 23);
				 this->button_Minijuego->TabIndex = 4;
				 this->button_Minijuego->Text = L"MINIJUEGO (Funcion Extra)";
				 this->button_Minijuego->UseVisualStyleBackColor = true;
				 this->button_Minijuego->Visible = false;
				 this->button_Minijuego->Click += gcnew System::EventHandler(this, &Juego::button_Minijuego_Click);
				 // 
				 // timer_Minijuego
				 // 
				 this->timer_Minijuego->Tick += gcnew System::EventHandler(this, &Juego::timer_Minijuego_Tick);
				 // 
				 // Juego
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(726, 550);
				 this->Controls->Add(this->button_Minijuego);
				 this->Controls->Add(this->button_Salir);
				 this->Controls->Add(this->button_Creditos);
				 this->Controls->Add(this->button_Jugar);
				 this->Controls->Add(this->pictureBox1);
				 this->KeyPreview = true;
				 this->Name = L"Juego";
				 this->Text = L"Juego";
				 this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion


	private:

	private: System::Void Juego_Load(System::Object^  sender, System::EventArgs^  e) {
		r = gcnew Random;

		////Creacio de buffer necesario para inicializar datos en Nivel
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, ClientRectangle);

		/////Creo personaje y asigno img a Map
		Personaje = new C_Personaje;
		Personaje->Definir(0, 0, 0, 0, 6, 8);
		Map = gcnew Bitmap(pictureBox1->Image);
		/////Creo niveles y asigno personaje y buffer
		Nivel1 = new C_Nivel(Personaje);
		Nivel1->Inicializar(1, Buffer);

		Nivel2 = new C_Nivel(Personaje);
		Nivel2->Inicializar(2, Buffer);

		Nivel3 = new C_Nivel(Personaje);
		Nivel3->Inicializar(3, Buffer);

		Nivel4 = new C_Nivel(Personaje);
		Nivel4->Inicializar(4, Buffer);

		Nivel5 = new C_Nivel(Personaje);
		Nivel5->Inicializar(5, Buffer);



		//////Hago transparente las imagenes
		bmpPersonaje->MakeTransparent(bmpPersonaje->GetPixel(1, 1));
		bmpPersonajeX->MakeTransparent(bmpPersonaje->GetPixel(1, 1));
		bmpDisco->MakeTransparent(bmpDisco->GetPixel(1, 1));
		bmpDiscoX->MakeTransparent(bmpDisco->GetPixel(1, 1));



		////Borro el buffer y demas
		delete Buffer;
		delete Espacio_Buffer;
		delete g;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//////Creo buffer y demas para dibujar y luego mostrar
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, ClientRectangle);
		String ^Texto;

		/////Creo texto que voy a mostrar
		if (Level1) {
			Texto = "Vidas: " + Personaje->getVidas() + "     " + "Tiempo: " + Nivel1->getTiempo_Nivel() + "     " + "Nivel: " + Nivel1->getNivel() + "     " + "Intentos de camara lenta: " + Nivel1->getIntentos_Camara_Lenta() + "     " + (Nivel1->getModo_Lento() ? "SLOW" : "NORMAL");

			Nivel1->Mover_Elementos(g, Buffer, bmpPersonaje, bmpPersonajeX, bmpDisco, bmpDiscoX, Map);

			//////Dibujo Rect y muestro datos
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 500, 726, 50);
			Buffer->Graphics->DrawString(Texto, Fuente, (Nivel1->getModo_Lento() ? Brushes::Red : Brushes::White), 5, 520);

			/////Verifico si el modo lento esta activado
			if (Nivel1->getModo_Lento()) {
				//////Aumento contador para simular tiempo y luego cambiar datos si tiempo se acabo
				contadorML += 1;
				if (contadorML >= Nivel1->getTiempo_Modo_Lento() * 10) {
					Nivel1->setModo_Lento(false);
					contadorML = 0;
				}
			}

			//////Simulo tiempo del nivel
			contadorT += 1;
			if (contadorT == 10) {
				Nivel1->setTiempo_Nivel(Nivel1->getTiempo_Nivel() - 1);
				contadorT = 0;
			}

			/////Simulo tiempo para aparecer nuevo disco
			if (Nivel1->getDiscos_Activos() < Nivel1->getCantidad_Discos()) {
				contadorD += 1;
				if (contadorD == Tiempo_Nuevo_Disco) {
					Nivel1->setDiscos_Activos(Nivel1->getDiscos_Activos() + 1);
					contadorD = 0;
					Tiempo_Nuevo_Disco = r->Next(15, 80);
				}
			}

			if (Nivel1->getTiempo_Nivel() == 0 && Personaje->getVidas() >= 0) {
				Posicion_X_Banner = 5;
				Level1 = false;
				Level2 = true;
				timer_Banners->Enabled = true;
				timer_Niveles->Enabled = false;
			}

		}
		else if (Level2) {
			Texto = "Vidas: " + Personaje->getVidas() + "     " + "Tiempo: " + Nivel2->getTiempo_Nivel() + "     " + "Nivel: " + Nivel2->getNivel() + "     " + "Intentos de camara lenta: " + Nivel2->getIntentos_Camara_Lenta() + "     " + (Nivel2->getModo_Lento() ? "SLOW" : "NORMAL");

			Nivel2->Mover_Elementos(g, Buffer, bmpPersonaje, bmpPersonajeX, bmpDisco, bmpDiscoX, Map);

			//////Dibujo Rect y muestro datos
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 500, 716, 50);
			Buffer->Graphics->DrawString(Texto, Fuente, (Nivel2->getModo_Lento() ? Brushes::Red : Brushes::White), 5, 510);

			/////Verifico si el modo lento esta activado
			if (Nivel2->getModo_Lento()) {
				//////Aumento contador para simular tiempo y luego cambiar datos si tiempo se acabo
				contadorML += 1;
				if (contadorML >= Nivel2->getTiempo_Modo_Lento() * 10) {
					Nivel2->setModo_Lento(false);
					contadorML = 0;
				}
			}

			//////Simulo tiempo del nivel
			contadorT += 1;
			if (contadorT == 10) {
				Nivel2->setTiempo_Nivel(Nivel2->getTiempo_Nivel() - 1);
				contadorT = 0;
			}

			/////Simulo tiempo para aparecer nuevo disco
			if (Nivel2->getDiscos_Activos() < Nivel2->getCantidad_Discos()) {
				contadorD += 1;
				if (contadorD == Tiempo_Nuevo_Disco) {
					Nivel2->setDiscos_Activos(Nivel2->getDiscos_Activos() + 1);
					contadorD = 0;
					Tiempo_Nuevo_Disco = r->Next(15, 70);
				}
			}

			if (Nivel2->getTiempo_Nivel() == 0 && Personaje->getVidas() >= 0) {
				Level2 = false;
				Level3 = true;
				Posicion_X_Banner = 5;
				timer_Banners->Enabled = true;
				timer_Niveles->Enabled = false;
			}

		}
		else if (Level3) {
			Texto = "Vidas: " + Personaje->getVidas() + "     " + "Tiempo: " + Nivel3->getTiempo_Nivel() + "     " + "Nivel: " + Nivel3->getNivel() + "     " + "Intentos de camara lenta: " + Nivel3->getIntentos_Camara_Lenta() + "     " + (Nivel3->getModo_Lento() ? "SLOW" : "NORMAL");

			Nivel3->Mover_Elementos(g, Buffer, bmpPersonaje, bmpPersonajeX, bmpDisco, bmpDiscoX, Map);

			//////Dibujo Rect y muestro datos
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 500, 726, 50);
			Buffer->Graphics->DrawString(Texto, Fuente, (Nivel3->getModo_Lento() ? Brushes::Red : Brushes::White), 5, 520);

			/////Verifico si el modo lento esta activado
			if (Nivel3->getModo_Lento()) {
				//////Aumento contador para simular tiempo y luego cambiar datos si tiempo se acabo
				contadorML += 1;
				if (contadorML >= Nivel3->getTiempo_Modo_Lento() * 10) {
					Nivel3->setModo_Lento(false);
					contadorML = 0;
				}
			}

			//////Simulo tiempo del nivel
			contadorT += 1;
			if (contadorT == 10) {
				Nivel3->setTiempo_Nivel(Nivel3->getTiempo_Nivel() - 1);
				contadorT = 0;
			}

			/////Simulo tiempo para aparecer nuevo disco
			if (Nivel3->getDiscos_Activos() < Nivel3->getCantidad_Discos()) {
				contadorD += 1;
				if (contadorD == Tiempo_Nuevo_Disco) {
					Nivel3->setDiscos_Activos(Nivel3->getDiscos_Activos() + 1);
					contadorD = 0;
					Tiempo_Nuevo_Disco = r->Next(15, 65);
				}
			}

			if (Nivel3->getTiempo_Nivel() == 0 && Personaje->getVidas() >= 0) {
				Level3 = false;
				Level4 = true;
				Posicion_X_Banner = 5;
				timer_Banners->Enabled = true;
				timer_Niveles->Enabled = false;
			}

		}
		else if (Level4) {
			Texto = "Vidas: " + Personaje->getVidas() + "     " + "Tiempo: " + Nivel4->getTiempo_Nivel() + "     " + "Nivel: " + Nivel4->getNivel() + "     " + "Intentos de camara lenta: " + Nivel4->getIntentos_Camara_Lenta() + "     " + (Nivel4->getModo_Lento() ? "SLOW" : "NORMAL");

			Nivel4->Mover_Elementos(g, Buffer, bmpPersonaje, bmpPersonajeX, bmpDisco, bmpDiscoX, Map);

			//////Dibujo Rect y muestro datos
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 500, 726, 50);
			Buffer->Graphics->DrawString(Texto, Fuente, (Nivel4->getModo_Lento() ? Brushes::Red : Brushes::White), 5, 520);

			/////Verifico si el modo lento esta activado
			if (Nivel4->getModo_Lento()) {
				//////Aumento contador para simular tiempo y luego cambiar datos si tiempo se acabo
				contadorML += 1;
				if (contadorML >= Nivel4->getTiempo_Modo_Lento() * 10) {
					Nivel4->setModo_Lento(false);
					contadorML = 0;
				}
			}

			//////Simulo tiempo del nivel
			contadorT += 1;
			if (contadorT == 10) {
				Nivel4->setTiempo_Nivel(Nivel4->getTiempo_Nivel() - 1);
				contadorT = 0;
			}

			/////Simulo tiempo para aparecer nuevo disco
			if (Nivel4->getDiscos_Activos() < Nivel4->getCantidad_Discos()) {
				contadorD += 1;
				if (contadorD == Tiempo_Nuevo_Disco) {
					Nivel4->setDiscos_Activos(Nivel4->getDiscos_Activos() + 1);
					contadorD = 0;
					Tiempo_Nuevo_Disco = r->Next(10, 50);
				}
			}

			if (Nivel4->getTiempo_Nivel() == 0 && Personaje->getVidas() >= 0) {
				Level4 = false;
				Level5 = true;
				Posicion_X_Banner = 5;
				timer_Banners->Enabled = true;
				timer_Niveles->Enabled = false;
			}

		}
		else if (Level5) {
			Texto = "Vidas: " + Personaje->getVidas() + "     " + "Tiempo: " + Nivel5->getTiempo_Nivel() + "     " + "Nivel: " + Nivel5->getNivel() + "     " + "Intentos de camara lenta: " + Nivel5->getIntentos_Camara_Lenta() + "     " + (Nivel5->getModo_Lento() ? "SLOW" : "NORMAL");

			Nivel5->Mover_Elementos(g, Buffer, bmpPersonaje, bmpPersonajeX, bmpDisco, bmpDiscoX, Map);

			//////Dibujo Rect y muestro datos
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 500, 726, 50);
			Buffer->Graphics->DrawString(Texto, Fuente, (Nivel5->getModo_Lento() ? Brushes::Red : Brushes::White), 1, 520);

			/////Verifico si el modo lento esta activado
			if (Nivel5->getModo_Lento()) {
				//////Aumento contador para simular tiempo y luego cambiar datos si tiempo se acabo
				contadorML += 1;
				if (contadorML >= Nivel5->getTiempo_Modo_Lento() * 10) {
					Nivel5->setModo_Lento(false);
					contadorML = 0;
				}
			}

			//////Simulo tiempo del nivel
			contadorT += 1;
			if (contadorT == 10) {
				Nivel5->setTiempo_Nivel(Nivel5->getTiempo_Nivel() - 1);
				contadorT = 0;
			}

			/////Simulo tiempo para aparecer nuevo disco
			if (Nivel5->getDiscos_Activos() < Nivel5->getCantidad_Discos()) {
				contadorD += 1;
				if (contadorD == Tiempo_Nuevo_Disco) {
					Nivel5->setDiscos_Activos(Nivel5->getDiscos_Activos() + 1);
					contadorD = 0;
					Tiempo_Nuevo_Disco = r->Next(10, 50);
				}
			}

			if (Nivel5->getTiempo_Nivel() == 0 && Personaje->getVidas() >= 0) {
				Level5 = false;
				Ganar = true;
				Posicion_X_Banner = 5;
				timer_Banners->Enabled = true;
				timer_Niveles->Enabled = false;
			}

		}
		else {

		}


		if (Personaje->getVidas() < 0) {
			Level1 = false;
			Level2 = false;
			Level3 = false;
			Level4 = false;
			Level5 = false;
			Ganar = false;
			Perder = true;
		}




		//////Renderizo y elimino buffer
		Buffer->Render(g);
		delete Buffer;
		delete Espacio_Buffer;
		delete g;
		delete Texto;

	}

	private: System::Void timer_Banners_Tick(System::Object^  sender, System::EventArgs^  e) {
		//////Creo buffer y demas para dibujar y luego mostrar
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, ClientRectangle);

		//////Dibujo Rect y muestro datos
		if (Level1) {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("Nivel 1", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}
		else if (Level2) {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("Nivel 2", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}
		else if (Level3) {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("Nivel 3", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}
		else if (Level4) {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("Nivel 4", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}
		else if (Level5) {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("Nivel 5", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}
		else if (Ganar) {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("F E L I C I D A D E S", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}
		else {
			Buffer->Graphics->Clear(Color::White);
			Buffer->Graphics->FillRectangle(Brushes::Black, 0, 250, 726, 50);
			Buffer->Graphics->DrawString("P E R D I S T E", Fuente, Brushes::Red, Posicion_X_Banner, 252);
		}


		//////Simulo tiempo 
		contadorT += 1;
		if (contadorT == 25) {
			timer_Banners->Enabled = false;
			timer_Niveles->Enabled = true;
			contadorT = 0;
			if (Ganar || Perder) {
				this->Close();
			}
			Personaje->setPosicion_X(r->Next(2, Buffer->Graphics->VisibleClipBounds.Width - Personaje->getAncho()));
			Personaje->setPosicion_Y(r->Next(2, Buffer->Graphics->VisibleClipBounds.Height - Personaje->getAlto()) - 60);
		}

		Posicion_X_Banner += 25;


		//////Renderizo y elimino buffer
		Buffer->Render(g);
		delete Buffer;
		delete Espacio_Buffer;
		delete g;

	}
	private: System::Void timer_Menu_Tick(System::Object^  sender, System::EventArgs^  e) {
		button_Jugar->Visible = true;
		button_Creditos->Visible = true;
		button_Salir->Visible = true;
		button_Minijuego->Visible = true;
		////Creacio de buffer 
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, ClientRectangle);
		Rectangle Area_Usar = Rectangle(0, 0, 1920, 1078);
		Rectangle Area_Dibujar = Rectangle(0, 0, Buffer->Graphics->VisibleClipBounds.Width, Buffer->Graphics->VisibleClipBounds.Height);



		/////
		Buffer->Graphics->DrawImage(bmpMario_Menu, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel);
		Buffer->Graphics->DrawString("Disc Room", Fuente_Menu, Brushes::Blue, Posicion_X_Menu, Posicion_Y_Menu);
		Buffer->Graphics->DrawString("Mario", Fuente_Menu, Brushes::Red, Posicion_X_Menu + 40, Posicion_Y_Menu + 50);





		if (Posicion_X_Menu<0 || Posicion_X_Menu + 200 > Buffer->Graphics->VisibleClipBounds.Width) {
			Movimiento_X_Menu *= -1;
		}

		Posicion_X_Menu += Movimiento_X_Menu;




		Buffer->Render(g);

		////Borro el buffer y demas
		delete Buffer;
		delete Espacio_Buffer;
		delete g;
	}
	private: System::Void timer_Creditos_Tick(System::Object^  sender, System::EventArgs^  e) {
		button_Jugar->Visible = false;
		button_Creditos->Visible = false;
		button_Salir->Visible = false;

		////Creacio de buffer 
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, ClientRectangle);
		//Rectangle Area_Usar = Rectangle(0, 0, 1920, 1078);
		//Rectangle Area_Dibujar = Rectangle(0, 0, Buffer->Graphics->VisibleClipBounds.Width, Buffer->Graphics->VisibleClipBounds.Height);



		/////
		Buffer->Graphics->Clear(Color::Black);

		Buffer->Graphics->DrawString("PROFESOR", Fuente, Brushes::Red, 300, 100);
		Buffer->Graphics->DrawString("Abraham   Sopla   Maslucan", Fuente, Brushes::Red, 100, 150);

		Buffer->Graphics->DrawString("ALUMNOS", Fuente, Brushes::Red, 300, 250);
		Buffer->Graphics->DrawString("Arthur   Javier   Valladares   Nole            U201810503", Fuente, Brushes::Red, 100, 300);
		Buffer->Graphics->DrawString("Gerardo   Gabriel  Caldas   Diaz                U201512034", Fuente, Brushes::Red, 100, 330);






		Buffer->Render(g);

		////Borro el buffer y demas
		delete Buffer;
		delete Espacio_Buffer;
		delete g;
	}

	private: System::Void button_Salir_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void button_Jugar_Click(System::Object^  sender, System::EventArgs^  e) {
		button_Jugar->Visible = false;
		button_Creditos->Visible = false;
		button_Salir->Visible = false;
		button_Minijuego->Visible = false;
		timer_Menu->Enabled = false;
		timer_Banners->Enabled = true;
	}
	private: System::Void button_Creditos_Click(System::Object^  sender, System::EventArgs^  e) {
		timer_Creditos->Enabled = true;
		timer_Menu->Enabled = false;
	}



	private: System::Void Juego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			Personaje->Tecla_Presionada = Izquierda;
			break;
		case Keys::Right:
			Personaje->Tecla_Presionada = Derecha;
			break;
		case Keys::Up:
			Personaje->Tecla_Presionada = Arriba;
			break;
		case Keys::Down:
			Personaje->Tecla_Presionada = Abajo;
			break;
		case Keys::T:
			Personaje->setPosicion_X(Personaje->getPosicion_X() - (r->Next(Personaje->getPosicion_X())));
			Personaje->setPosicion_Y(r->Next(350));
			break;
		case Keys::N:
			if (Level1) {
				Level1 = false;
				Level2 = true;
			}
			else if (Level2) {
				Level2 = false;
				Level3 = true;
			}
			else if (Level3) {
				Level3 = false;
				Level4 = true;
			}
			else if (Level4) {
				Level4 = false;
				Level5 = true;
			}
			else {
				Level5 = false;
				Ganar = true;
			}
			break;
		case Keys::C:
			//////Verifico que aun tenga intentos
			if (Nivel1->getIntentos_Camara_Lenta() > 0 && Level1) {
				////Activo modo lento y disminuyo intentos
				Nivel1->setModo_Lento(true);
				Nivel1->setIntentos_Camara_Lenta(Nivel1->getIntentos_Camara_Lenta() - 1);
			}
			else if (Nivel2->getIntentos_Camara_Lenta() > 0 && Level2) {
				////Activo modo lento y disminuyo intentos
				Nivel2->setModo_Lento(true);
				Nivel2->setIntentos_Camara_Lenta(Nivel2->getIntentos_Camara_Lenta() - 1);
			}
			else if (Nivel3->getIntentos_Camara_Lenta() > 0 && Level3) {
				////Activo modo lento y disminuyo intentos
				Nivel3->setModo_Lento(true);
				Nivel3->setIntentos_Camara_Lenta(Nivel3->getIntentos_Camara_Lenta() - 1);
			}
			else if (Nivel4->getIntentos_Camara_Lenta() > 0 && Level4) {
				////Activo modo lento y disminuyo intentos
				Nivel4->setModo_Lento(true);
				Nivel4->setIntentos_Camara_Lenta(Nivel4->getIntentos_Camara_Lenta() - 1);
			}
			else if (Nivel5->getIntentos_Camara_Lenta() > 0 && Level5) {
				////Activo modo lento y disminuyo intentos
				Nivel5->setModo_Lento(true);
				Nivel5->setIntentos_Camara_Lenta(Nivel5->getIntentos_Camara_Lenta() - 1);
			}
			else {

			}
			break;
		case Keys::J:
			Personaje->setVidas(Personaje->getVidas() + 1);
			break;
		case Keys::A:
			timer_Creditos->Enabled = false;
			timer_Banners->Enabled = false;
			timer_Minijuego->Enabled = false;
			timer_Niveles->Enabled = false;
			timer_Menu->Enabled = true;
			break;
		}
	}
private: System::Void Juego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	Personaje->Tecla_Presionada = Ninguna;
	switch (e->KeyCode)
	{
	case Keys::Left:
		Personaje->Tecla_Ultima = Izquierda;
		break;
	case Keys::Right:
		Personaje->Tecla_Ultima = Derecha;
		break;
	case Keys::Up:
		Personaje->Tecla_Ultima = Arriba;
		break;
	case Keys::Down:
		Personaje->Tecla_Ultima = Abajo;
		break;

	}
}

/////Seccion minijuego
private: System::Void button_Minijuego_Click(System::Object^  sender, System::EventArgs^  e) {
	Graphics ^g = this->CreateGraphics();
	BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
	BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, this->ClientRectangle);
	button_Jugar->Visible = false;
	button_Creditos->Visible = false;
	button_Salir->Visible = false;
	button_Minijuego->Visible = false;
	timer_Menu->Enabled = false;
	timer_Minijuego->Enabled = true;

	Minijuego = new C_Minijuego;
	Minijuego->Definir(Buffer);

	delete Buffer;
	delete Espacio_Buffer;
	delete g;
}



private: System::Void timer_Minijuego_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics ^g = this->CreateGraphics();
	BufferedGraphicsContext ^Espacio_Buffer = BufferedGraphicsManager::Current;
	BufferedGraphics ^Buffer = Espacio_Buffer->Allocate(g, this->ClientRectangle);


	Buffer->Graphics->Clear(Color::Gray);
	
	Minijuego->Mover_Elementos(Buffer, bmpBomba,Iterador_Bomba);

	if (Minijuego->getBomba()[Iterador_Bomba].getExploto()) {
		Iterador_Bomba += 1;
	}

	if (Iterador_Bomba == Minijuego->getCantidad_Bombas()) {
		timer_Menu->Enabled = true;
		timer_Minijuego->Enabled = false;
	}


	Buffer->Render(g);

	delete Buffer;
	delete Espacio_Buffer;
	delete g;
}
};
}

