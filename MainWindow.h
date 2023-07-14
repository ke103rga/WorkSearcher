#include "EmployerWindow.h"
#include "CandidateWindow.h"
#include <windows.h>
#include <shellapi.h>

#pragma once

namespace WorkSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Mainwindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ sloganLabel;
	private: System::Windows::Forms::LinkLabel^ helpLinkLabel;
	private: System::Windows::Forms::PictureBox^ LogoPictureBox;



	private: System::Windows::Forms::LinkLabel^ authorLinkedLabel;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ employerButton;
	private: System::Windows::Forms::Button^ candidateButton;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->sloganLabel = (gcnew System::Windows::Forms::Label());
			this->helpLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->LogoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->authorLinkedLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->employerButton = (gcnew System::Windows::Forms::Button());
			this->candidateButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// sloganLabel
			// 
			this->sloganLabel->AutoSize = true;
			this->sloganLabel->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB Demi", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sloganLabel->Location = System::Drawing::Point(95, 46);
			this->sloganLabel->Name = L"sloganLabel";
			this->sloganLabel->Size = System::Drawing::Size(306, 24);
			this->sloganLabel->TabIndex = 0;
			this->sloganLabel->Text = L"Работа найдётся для каждого";
			// 
			// helpLinkLabel
			// 
			this->helpLinkLabel->AutoSize = true;
			this->helpLinkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->helpLinkLabel->LinkColor = System::Drawing::Color::DimGray;
			this->helpLinkLabel->Location = System::Drawing::Point(96, 84);
			this->helpLinkLabel->Name = L"helpLinkLabel";
			this->helpLinkLabel->Size = System::Drawing::Size(58, 16);
			this->helpLinkLabel->TabIndex = 1;
			this->helpLinkLabel->TabStop = true;
			this->helpLinkLabel->Text = L"Помощь";
			this->helpLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainWindow::helpLinkLabel_LinkClicked);
			// 
			// LogoPictureBox
			// 
			this->LogoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoPictureBox.Image")));
			this->LogoPictureBox->Location = System::Drawing::Point(12, 37);
			this->LogoPictureBox->Name = L"LogoPictureBox";
			this->LogoPictureBox->Size = System::Drawing::Size(70, 63);
			this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LogoPictureBox->TabIndex = 2;
			this->LogoPictureBox->TabStop = false;
			// 
			// authorLinkedLabel
			// 
			this->authorLinkedLabel->AutoSize = true;
			this->authorLinkedLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->authorLinkedLabel->LinkColor = System::Drawing::Color::DimGray;
			this->authorLinkedLabel->Location = System::Drawing::Point(169, 84);
			this->authorLinkedLabel->Name = L"authorLinkedLabel";
			this->authorLinkedLabel->Size = System::Drawing::Size(47, 16);
			this->authorLinkedLabel->TabIndex = 3;
			this->authorLinkedLabel->TabStop = true;
			this->authorLinkedLabel->Text = L"Автор";
			this->authorLinkedLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainWindow::authorLinkedLabel_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 430);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 40);
			this->label1->TabIndex = 4;
			this->label1->Text = L"> 10 млн.\nрезюме";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(258, 430);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 40);
			this->label2->TabIndex = 5;
			this->label2->Text = L"> 500 тыс. \nвакансий";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(136, 430);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 40);
			this->label3->TabIndex = 6;
			this->label3->Text = L"> 500 тыс. \nкомпаний";
			// 
			// employerButton
			// 
			this->employerButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->employerButton->Location = System::Drawing::Point(99, 273);
			this->employerButton->Name = L"employerButton";
			this->employerButton->Size = System::Drawing::Size(191, 95);
			this->employerButton->TabIndex = 8;
			this->employerButton->Text = L"Продолжить как работодатель";
			this->employerButton->UseVisualStyleBackColor = true;
			this->employerButton->Click += gcnew System::EventHandler(this, &MainWindow::employerButton_Click);
			// 
			// candidateButton
			// 
			this->candidateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->candidateButton->Location = System::Drawing::Point(99, 155);
			this->candidateButton->Name = L"candidateButton";
			this->candidateButton->Size = System::Drawing::Size(191, 96);
			this->candidateButton->TabIndex = 9;
			this->candidateButton->Text = L"Продолжить как соискатель";
			this->candidateButton->UseVisualStyleBackColor = true;
			this->candidateButton->Click += gcnew System::EventHandler(this, &MainWindow::candidateButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(297, 173);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(315, 60);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Выбирайте подходящую для вас работу\nиз тысяч предложенных вакансий\nнастраивая нуж"
				L"ные параметры поиска";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(297, 293);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(281, 60);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Добавляйте вакансии для поиска\n необходимых специалистов\nи удаляйте неактуальные "
				L"вакансии";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 484);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->candidateButton);
			this->Controls->Add(this->employerButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->authorLinkedLabel);
			this->Controls->Add(this->LogoPictureBox);
			this->Controls->Add(this->helpLinkLabel);
			this->Controls->Add(this->sloganLabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->Text = L"WorkSearcher";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

private: System::Void candidateButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//Open form for candidates
	CandidateWindow^ form = gcnew CandidateWindow();
	form->ShowDialog();
}

private: System::Void employerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//Open form for employer
	EmployerWindow^ form = gcnew EmployerWindow();
	form->ShowDialog();
}

private: System::Void helpLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	//Showing the dialog window which contains instractions for user
	String^ helpMessage = "Для поиска работы воспользуйтесь разделом \"Для соискателей\"\nДля поиска сотрудников воспользуйтесь разделом \"Для работодателей\"\n";
	MessageBox::MessageBox::Show(helpMessage, L"У тебя какие-то проблемы?", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

private: System::Void authorLinkedLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	//Showing the dialog window which contains information about author
	String^ authorMessage = "Автор программы: Ра
		зуев Георгий\nGitHub: https://github.com/ke103rga";
	MessageBox::MessageBox::Show(authorMessage, L"Создатель", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	return;
}
};
}
