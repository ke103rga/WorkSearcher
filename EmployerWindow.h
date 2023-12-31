#include <regex>
#include <iostream>
#include <fstream>
#include "Vacancies.h"
#include "InputDataValidator.h"
#include <msclr\marshal_cppstd.h>

using namespace System::Collections::Generic;

#pragma once

namespace WorkSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� EmployerWindow
	/// </summary>
	public ref class EmployerWindow : public System::Windows::Forms::Form
	{
	public:
		bool choosedFile = false;
		bool fileChanged = false;
		String^ logoFile;
	private: System::Windows::Forms::CheckBox^ chooseActionTheckBox;
	
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ correctVacIdTextBox;
	private: System::Windows::Forms::Button^ startCorrectButton;
		   List<RichTextBox^> inputFields;
	public:
		EmployerWindow(void)
		{
			InitializeComponent();

			ToolTip^ uniToolTip = gcnew ToolTip;
			uniToolTip->AutoPopDelay = 50000;
			uniToolTip->InitialDelay = 1;
			uniToolTip->ReshowDelay = 5000;
			uniToolTip->ShowAlways = true;
			uniToolTip->SetToolTip(this->reqTipLabel, "������� ������ ����������� ������� ����� �������");
			uniToolTip->SetToolTip(this->trialPerTipLabel, "������� ���������� ����, ������� ���������� ������������ �������������� �����.\n���� ���� ��� ������ ������� �� �������������� - ������� 0.");
			uniToolTip->SetToolTip(this->SceduleTipLabel, "������� ���� �� ���������:\n*   5/2\n*   2/2\n*   ����������\n*   ���������");
			
			inputFields.Add(companyTextBox);
			inputFields.Add(vacancyTextBox);
			inputFields.Add(salaryTextBox);
			inputFields.Add(sceduleTextBox);
			inputFields.Add(trialPerTextBox);
			inputFields.Add(emailTextBox);
			inputFields.Add(phoneNumberTextBox);
			inputFields.Add(reqTextBox);

			label11->Visible = false;
			correctVacIdTextBox->Visible = false;
			startCorrectButton->Visible = false;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~EmployerWindow()
		{
			//vacancies.saveChanges(DB_FILE_PATH);
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ LogoPictureBox;
	private: System::Windows::Forms::LinkLabel^ helpLinkLabel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ companyTextBox;
	private: System::Windows::Forms::RichTextBox^ vacancyTextBox;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RichTextBox^ salaryTextBox;
	private: System::Windows::Forms::RichTextBox^ sceduleTextBox;
	private: System::Windows::Forms::RichTextBox^ trialPerTextBox;
	private: System::Windows::Forms::RichTextBox^ emailTextBox;
	private: System::Windows::Forms::RichTextBox^ phoneNumberTextBox;
	private: System::Windows::Forms::RichTextBox^ reqTextBox;






	private: System::Windows::Forms::Button^ selectLogoButon;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ reqTipLabel;
	private: System::Windows::Forms::Label^ trialPerTipLabel;
	private: System::Windows::Forms::Label^ SceduleTipLabel;



	private: System::Windows::Forms::Button^ addVacancyButton;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::RichTextBox^ vacIdTextBox;

	private: System::Windows::Forms::Button^ deleteVacancyButton;

	/*private: System::Windows::Forms::Button^ CorrectExistvacButton;
	private: System::Windows::Forms::Label^ label11;*/


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EmployerWindow::typeid));
			this->LogoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->helpLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->trialPerTipLabel = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->companyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->vacancyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->salaryTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->sceduleTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->trialPerTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->emailTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->reqTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->selectLogoButon = (gcnew System::Windows::Forms::Button());
			this->reqTipLabel = (gcnew System::Windows::Forms::Label());
			this->SceduleTipLabel = (gcnew System::Windows::Forms::Label());
			this->phoneNumberTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->addVacancyButton = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->vacIdTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->deleteVacancyButton = (gcnew System::Windows::Forms::Button());
			this->chooseActionTheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->correctVacIdTextBox = (gcnew System::Windows::Forms::TextBox());
			this->startCorrectButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// LogoPictureBox
			// 
			this->LogoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoPictureBox.Image")));
			this->LogoPictureBox->Location = System::Drawing::Point(18, 18);
			this->LogoPictureBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->LogoPictureBox->Name = L"LogoPictureBox";
			this->LogoPictureBox->Size = System::Drawing::Size(105, 97);
			this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LogoPictureBox->TabIndex = 4;
			this->LogoPictureBox->TabStop = false;
			// 
			// helpLinkLabel
			// 
			this->helpLinkLabel->AutoSize = true;
			this->helpLinkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->helpLinkLabel->LinkColor = System::Drawing::Color::DimGray;
			this->helpLinkLabel->Location = System::Drawing::Point(132, 18);
			this->helpLinkLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->helpLinkLabel->Name = L"helpLinkLabel";
			this->helpLinkLabel->Size = System::Drawing::Size(92, 25);
			this->helpLinkLabel->TabIndex = 5;
			this->helpLinkLabel->TabStop = true;
			this->helpLinkLabel->Text = L"������";
			this->helpLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &EmployerWindow::helpLinkLabel_LinkClicked);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				34)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.93315F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				64.06685F)));
			this->tableLayoutPanel1->Controls->Add(this->trialPerTipLabel, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label9, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->label1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->companyTextBox, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label5, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->label7, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->label8, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->vacancyTextBox, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->salaryTextBox, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->sceduleTextBox, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->trialPerTextBox, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->emailTextBox, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->reqTextBox, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->selectLogoButon, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->reqTipLabel, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->SceduleTipLabel, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->phoneNumberTextBox, 2, 7);
			this->tableLayoutPanel1->Location = System::Drawing::Point(491, 182);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 9;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(573, 563);
			this->tableLayoutPanel1->TabIndex = 6;
			// 
			// trialPerTipLabel
			// 
			this->trialPerTipLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->trialPerTipLabel->AutoSize = true;
			this->trialPerTipLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->trialPerTipLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->trialPerTipLabel->Location = System::Drawing::Point(4, 310);
			this->trialPerTipLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->trialPerTipLabel->Name = L"trialPerTipLabel";
			this->trialPerTipLabel->Size = System::Drawing::Size(26, 62);
			this->trialPerTipLabel->TabIndex = 19;
			this->trialPerTipLabel->Text = L"\?";
			this->trialPerTipLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(38, 496);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(185, 67);
			this->label9->TabIndex = 10;
			this->label9->Text = L"���������� � �����������";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(38, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 62);
			this->label1->TabIndex = 0;
			this->label1->Text = L"��������";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// companyTextBox
			// 
			this->companyTextBox->Location = System::Drawing::Point(231, 5);
			this->companyTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->companyTextBox->Name = L"companyTextBox";
			this->companyTextBox->Size = System::Drawing::Size(332, 50);
			this->companyTextBox->TabIndex = 1;
			this->companyTextBox->Text = L"";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(38, 62);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(185, 62);
			this->label2->TabIndex = 3;
			this->label2->Text = L"�������";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(38, 124);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(185, 62);
			this->label3->TabIndex = 4;
			this->label3->Text = L"�������� ��������";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(38, 186);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(185, 62);
			this->label4->TabIndex = 5;
			this->label4->Text = L"��������";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(38, 248);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(185, 62);
			this->label5->TabIndex = 6;
			this->label5->Text = L"������� ������";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(38, 310);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(185, 62);
			this->label6->TabIndex = 7;
			this->label6->Text = L"������������� ����";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(38, 372);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(185, 62);
			this->label7->TabIndex = 8;
			this->label7->Text = L"email";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(38, 434);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(185, 62);
			this->label8->TabIndex = 9;
			this->label8->Text = L"�������";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// vacancyTextBox
			// 
			this->vacancyTextBox->Location = System::Drawing::Point(231, 129);
			this->vacancyTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->vacancyTextBox->Name = L"vacancyTextBox";
			this->vacancyTextBox->Size = System::Drawing::Size(332, 50);
			this->vacancyTextBox->TabIndex = 2;
			this->vacancyTextBox->Text = L"";
			// 
			// salaryTextBox
			// 
			this->salaryTextBox->Location = System::Drawing::Point(231, 191);
			this->salaryTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->salaryTextBox->Name = L"salaryTextBox";
			this->salaryTextBox->Size = System::Drawing::Size(332, 50);
			this->salaryTextBox->TabIndex = 11;
			this->salaryTextBox->Text = L"";
			// 
			// sceduleTextBox
			// 
			this->sceduleTextBox->Location = System::Drawing::Point(231, 253);
			this->sceduleTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->sceduleTextBox->Name = L"sceduleTextBox";
			this->sceduleTextBox->Size = System::Drawing::Size(332, 50);
			this->sceduleTextBox->TabIndex = 12;
			this->sceduleTextBox->Text = L"";
			// 
			// trialPerTextBox
			// 
			this->trialPerTextBox->Location = System::Drawing::Point(231, 315);
			this->trialPerTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->trialPerTextBox->Name = L"trialPerTextBox";
			this->trialPerTextBox->Size = System::Drawing::Size(332, 50);
			this->trialPerTextBox->TabIndex = 13;
			this->trialPerTextBox->Text = L"";
			// 
			// emailTextBox
			// 
			this->emailTextBox->Location = System::Drawing::Point(231, 377);
			this->emailTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(332, 50);
			this->emailTextBox->TabIndex = 14;
			this->emailTextBox->Text = L"";
			// 
			// reqTextBox
			// 
			this->reqTextBox->Location = System::Drawing::Point(231, 501);
			this->reqTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->reqTextBox->Name = L"reqTextBox";
			this->reqTextBox->Size = System::Drawing::Size(332, 50);
			this->reqTextBox->TabIndex = 16;
			this->reqTextBox->Text = L"";
			// 
			// selectLogoButon
			// 
			this->selectLogoButon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->selectLogoButon->Location = System::Drawing::Point(231, 67);
			this->selectLogoButon->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->selectLogoButon->Name = L"selectLogoButon";
			this->selectLogoButon->Size = System::Drawing::Size(334, 52);
			this->selectLogoButon->TabIndex = 17;
			this->selectLogoButon->Text = L"������� ����";
			this->selectLogoButon->UseVisualStyleBackColor = true;
			this->selectLogoButon->Click += gcnew System::EventHandler(this, &EmployerWindow::selectLogoButon_Click);
			// 
			// reqTipLabel
			// 
			this->reqTipLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->reqTipLabel->AutoSize = true;
			this->reqTipLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->reqTipLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->reqTipLabel->Location = System::Drawing::Point(4, 496);
			this->reqTipLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->reqTipLabel->Name = L"reqTipLabel";
			this->reqTipLabel->Size = System::Drawing::Size(26, 67);
			this->reqTipLabel->TabIndex = 18;
			this->reqTipLabel->Text = L"\?";
			this->reqTipLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SceduleTipLabel
			// 
			this->SceduleTipLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SceduleTipLabel->AutoSize = true;
			this->SceduleTipLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->SceduleTipLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->SceduleTipLabel->Location = System::Drawing::Point(4, 248);
			this->SceduleTipLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SceduleTipLabel->Name = L"SceduleTipLabel";
			this->SceduleTipLabel->Size = System::Drawing::Size(26, 62);
			this->SceduleTipLabel->TabIndex = 20;
			this->SceduleTipLabel->Text = L"\?";
			this->SceduleTipLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// phoneNumberTextBox
			// 
			this->phoneNumberTextBox->Location = System::Drawing::Point(231, 439);
			this->phoneNumberTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->phoneNumberTextBox->Name = L"phoneNumberTextBox";
			this->phoneNumberTextBox->Size = System::Drawing::Size(332, 50);
			this->phoneNumberTextBox->TabIndex = 15;
			this->phoneNumberTextBox->Text = L"";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(512, 18);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(444, 58);
			this->label10->TabIndex = 7;
			this->label10->Text = L"��� ���������� ��������\n��������� ��� ����������� ����";
			// 
			// addVacancyButton
			// 
			this->addVacancyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addVacancyButton->Location = System::Drawing::Point(720, 781);
			this->addVacancyButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->addVacancyButton->Name = L"addVacancyButton";
			this->addVacancyButton->Size = System::Drawing::Size(334, 55);
			this->addVacancyButton->TabIndex = 8;
			this->addVacancyButton->Text = L"�������� ��������";
			this->addVacancyButton->UseVisualStyleBackColor = true;
			this->addVacancyButton->Click += gcnew System::EventHandler(this, &EmployerWindow::addVacancyButton_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(12, 209);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(355, 58);
			this->label14->TabIndex = 9;
			this->label14->Text = L"��� �������� ��������\n������� �� �������������";
			// 
			// vacIdTextBox
			// 
			this->vacIdTextBox->Location = System::Drawing::Point(18, 311);
			this->vacIdTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->vacIdTextBox->Name = L"vacIdTextBox";
			this->vacIdTextBox->Size = System::Drawing::Size(301, 50);
			this->vacIdTextBox->TabIndex = 21;
			this->vacIdTextBox->Text = L"";
			// 
			// deleteVacancyButton
			// 
			this->deleteVacancyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->deleteVacancyButton->Location = System::Drawing::Point(18, 405);
			this->deleteVacancyButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->deleteVacancyButton->Name = L"deleteVacancyButton";
			this->deleteVacancyButton->Size = System::Drawing::Size(303, 55);
			this->deleteVacancyButton->TabIndex = 22;
			this->deleteVacancyButton->Text = L"������� ��������";
			this->deleteVacancyButton->UseVisualStyleBackColor = true;
			this->deleteVacancyButton->Click += gcnew System::EventHandler(this, &EmployerWindow::deleteVacancyButton_Click);
			// 
			// chooseActionTheckBox
			// 
			this->chooseActionTheckBox->AutoSize = true;
			this->chooseActionTheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->chooseActionTheckBox->Location = System::Drawing::Point(491, 105);
			this->chooseActionTheckBox->Name = L"chooseActionTheckBox";
			this->chooseActionTheckBox->Size = System::Drawing::Size(180, 29);
			this->chooseActionTheckBox->TabIndex = 23;
			this->chooseActionTheckBox->Text = L"�������������";
			this->chooseActionTheckBox->UseVisualStyleBackColor = true;
			this->chooseActionTheckBox->CheckedChanged += gcnew System::EventHandler(this, &EmployerWindow::chooseActionTheckBox_CheckedChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(718, 95);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(290, 40);
			this->label11->TabIndex = 24;
			this->label11->Text = L"������� ������������� ��������,\n������� ���������� �������������";
			// 
			// correctVacIdTextBox
			// 
			this->correctVacIdTextBox->Location = System::Drawing::Point(722, 139);
			this->correctVacIdTextBox->Name = L"correctVacIdTextBox";
			this->correctVacIdTextBox->Size = System::Drawing::Size(208, 26);
			this->correctVacIdTextBox->TabIndex = 25;
			this->correctVacIdTextBox->TextChanged += gcnew System::EventHandler(this, &EmployerWindow::correctVacIdTextBox_TextChanged);
			// 
			// startCorrectButton
			// 
			this->startCorrectButton->Location = System::Drawing::Point(955, 138);
			this->startCorrectButton->Name = L"startCorrectButton";
			this->startCorrectButton->Size = System::Drawing::Size(194, 36);
			this->startCorrectButton->TabIndex = 26;
			this->startCorrectButton->Text = L"�������������";
			this->startCorrectButton->UseVisualStyleBackColor = true;
			this->startCorrectButton->Click += gcnew System::EventHandler(this, &EmployerWindow::startCorrectButton_Click);
			// 
			// EmployerWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1186, 891);
			this->Controls->Add(this->startCorrectButton);
			this->Controls->Add(this->correctVacIdTextBox);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->chooseActionTheckBox);
			this->Controls->Add(this->deleteVacancyButton);
			this->Controls->Add(this->vacIdTextBox);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->addVacancyButton);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->helpLinkLabel);
			this->Controls->Add(this->LogoPictureBox);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"EmployerWindow";
			this->Text = L"EmployerWindow";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EmployerWindow::setting_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

private: System::Void setting_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	//After click the close button if user made any changes
	//The dialog window will be shown that ask to confrim changes
	if (vacancies.savedChanges) { return; }
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("��������� ��� ��������� ���������?", "WorkSearcher", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		//If used said that he want to save changes it would be saved
		vacancies.saveChanges(DB_FILE_PATH);
	}
}
private: System::Void deleteVacancyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//Check if input field is empty
	if (vacIdTextBox->Text == "") {
		String^ helpMessage = "������� ������������� ��������";
		MessageBox::MessageBox::Show(helpMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	//Check if input field contains not int value
	if (!InputDataValidator::isInt(vacIdTextBox->Text)) {
		String^ helpMessage = "������������� �������� - ����� ������������� �����";
		MessageBox::MessageBox::Show(helpMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
		vacIdTextBox->Text = "������� ������������� ������������� ��������";
		return;
	}
	int idToDelete = Convert::ToInt32(this->vacIdTextBox->Text);
	//If databes contains vacancy with such id, it would be deleted
	if (vacancies.deleteVacancy(idToDelete)) {
		String^ successMessage = "�������� �������";
		MessageBox::MessageBox::Show(successMessage, L"�������!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		vacancies.savedChanges = false;
	}
	//User will be notificated about absence of that id
	else {
		String^ errorMessage = "�������� � ����� ��������������� ����������� � ����";
		MessageBox::MessageBox::Show(errorMessage, L"�������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	vacIdTextBox->Text = "";
}

private: System::Void helpLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	String^ helpMessage = "��� �������� �������� ������� �� �������������.\"\n��� �������� ����� ���������� ��������� ��� ��������� ����\n��� ������������� ������������� ��������, �������� �������������� �����.\n�� �������������� ����������� �������������� ����������� �������� �������������� �����.";
	MessageBox::MessageBox::Show(helpMessage, L"� ���� �����-�� ��������?", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

	   bool anyEmptyFields() {
		   //Function that checks are there any fields without entered text
		   for (int i = 0; i != inputFields.Count; i++) {
			   if (inputFields[i]->Text == "") {
				   return true;
			   }
		   }
		   return !choosedFile;
	   }

       private: System::Void selectLogoButon_Click(System::Object^ sender, System::EventArgs^ e) {
		   //Function that opens dialog for file selection and checks if selected file has valid extension
		   OpenFileDialog^ ofd = gcnew OpenFileDialog();
		   ofd->Filter = "Image Files|*.png;";
		   ofd->ShowDialog();
		   logoFile = gcnew String(ofd->FileName->ToCharArray());
		   if (logoFile->Substring(logoFile->Length - 4) != ".png") {
			   String^ errorMessage = "���������� ������� ���� � ����������� \".png\"";
			   MessageBox::MessageBox::Show(errorMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		   }
		   choosedFile = true;
		   if (chooseActionTheckBox->Checked) { fileChanged = true; }
       }

	   private: bool createVacancy(Vacancy* newVacancy) {
		   //Converting all texts from input fielda into std::string
		   string company = msclr::interop::marshal_as<std::string>(companyTextBox->Text);
		   string vacancy = msclr::interop::marshal_as<std::string>(vacancyTextBox->Text);
		   string salary = msclr::interop::marshal_as<std::string>(salaryTextBox->Text);
		   string scedule = msclr::interop::marshal_as<std::string>(sceduleTextBox->Text);
		   string trialPer = msclr::interop::marshal_as<std::string>(trialPerTextBox->Text);
		   string email = msclr::interop::marshal_as<std::string>(emailTextBox->Text);
		   string phoneNumber = msclr::interop::marshal_as<std::string>(phoneNumberTextBox->Text);
		   string candidateReq = msclr::interop::marshal_as<std::string>(reqTextBox->Text);
		   string logo = "companyLogos\\" + msclr::interop::marshal_as<std::string>(newVacancy->id.ToString()) + "LogoFile.png";

		   //Checking if any fields were filled incorrectly
		   InputDataValidator validator = InputDataValidator();
		   string errorMessage = "";
		   bool isDataValid = validator.isInputDataValid(company, vacancy, salary, scedule, trialPer,
			   email, phoneNumber, candidateReq, errorMessage, inputFields);

		   if (!isDataValid) {
			   MessageBox::MessageBox::Show(gcnew String(errorMessage.c_str()), L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return false;
		   }
		   //Copy the searched logo file if it was changed
		   if (!chooseActionTheckBox->Checked || fileChanged) {
			   std::ifstream src(msclr::interop::marshal_as<std::string>(logoFile->ToString()), std::ios::binary);
			   std::ofstream dest(logo, std::ios::binary);
			   dest << src.rdbuf();
		   }
		   
		   //Changing the fields of vacancy that were passed as an argument
		   newVacancy->company = company;
		   newVacancy->vacancyName = vacancy;
		   newVacancy->salary = Convert::ToInt32(salaryTextBox->Text);
		   newVacancy->workingSchedule = scedule;
		   newVacancy->trialPeriod = Convert::ToInt32(trialPerTextBox->Text);
		   newVacancy->phoneNumber = phoneNumber;
		   newVacancy->email = email;
		   newVacancy->candidateRequirement = validator.split(candidateReq, ", ");
		   if (!chooseActionTheckBox->Checked || fileChanged){ newVacancy->companyLogo = logo; }
		   return true;
	   }

private: System::Void addVacancyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//Checking are all input fields were filled
	if (anyEmptyFields()) {
		String^ errorMessage = "��������� ��� ����!";
		MessageBox::MessageBox::Show(errorMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error); 
		return; 
	}
	//If user selected to correct the existing vacancy
	//display the attributes of such vacancy
	if (chooseActionTheckBox->Checked) {
		int idToCorrect = Convert::ToInt32(this->correctVacIdTextBox->Text);
		Vacancy* newVacancy = vacancies.findById(idToCorrect);
		if(createVacancy(newVacancy)) {
			vacancies.updateVacancy(idToCorrect, *newVacancy);
			String^ Message = "�������� ���� ������� ���������.";
			MessageBox::MessageBox::Show(Message, L"�������!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			for (int i = 0; i != inputFields.Count; i++) {
				inputFields[i]->Text = "";
			}
			vacancies.savedChanges = false;
		}
	}
	//If user selected to create a new vacancy 
	//creating the new instance and filling it
	else {
		Vacancy* newVacancy = &Vacancy(vacancies.getNextId());
		if (createVacancy(newVacancy)) {
			int newId = vacancies.addVacancy(*newVacancy);
			String^ Message = "�������� ���� ������� �������.\n������������� ��������: " + newId.ToString();
			MessageBox::MessageBox::Show(Message, L"�������!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			for (int i = 0; i != inputFields.Count; i++) {
				inputFields[i]->Text = "";
			}
			vacancies.savedChanges = false;
		}
	}
}

private: System::Void CorrectExistvacButton_Click(System::Object^ sender, System::EventArgs^ e) {
	/*CorrectVacancyWindow^ form = gcnew CorrectVacancyWindow();
	form->ShowDialog();*/
	return;
}
private: System::Void chooseActionTheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//if user selected to corret existing vacancy
	//control elements for that operation become visible
	if (chooseActionTheckBox->Checked == true) {
		label11->Visible = true;
		correctVacIdTextBox->Visible = true;
		startCorrectButton->Visible = true;
		addVacancyButton->Text = "������������� ��������";
	}
	//if user selected to adnew vacancy
	//control elements for correcting become not visible
	else {
		label11->Visible = false;
		correctVacIdTextBox->Visible = false;
		startCorrectButton->Visible = false;
		addVacancyButton->Text = "�������� ��������";
		correctVacIdTextBox->Text = "";
	}
	//All information about last processed vacancy cleared
	for (int i = 0; i != inputFields.Count; i++) {
		inputFields[i]->Text = "";
	}
}
private: System::Void correctVacIdTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	return;
}
private: System::Void startCorrectButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool clear = false;
	//Ckcking if id was writed correctly
	if (correctVacIdTextBox->Text == "") {
		String^ helpMessage = "������� ������������� ��������";
		MessageBox::MessageBox::Show(helpMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
		clear = true;
	}
	if (!InputDataValidator::isInt(correctVacIdTextBox->Text)) {
		String^ helpMessage = "������������� �������� - ����� ������������� �����";
		MessageBox::MessageBox::Show(helpMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
		vacIdTextBox->Text = "������� ������������� ������������� ��������";
		clear = true;
	}
	int idToCorrect = Convert::ToInt32(this->correctVacIdTextBox->Text);
	if (!vacancies.containsId(idToCorrect)) {
		String^ helpMessage = "�������� � ����� ��������������� �� ���������� � ����";
		MessageBox::MessageBox::Show(helpMessage, L"������ �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
		vacIdTextBox->Text = "";
		clear = true;
	}
	//In case of incorrect id the inputfield will be cleared
	if (clear) {
		for (int i = 0; i != inputFields.Count; i++) {
			inputFields[i]->Text = "";
		}
		return;
	}
	//Otherwise all input fields will be filled by information of vacancy with such id
	Vacancy* vacToCorrect = vacancies.findById(idToCorrect);
	companyTextBox->Text = gcnew String(vacToCorrect->company.c_str());
	vacancyTextBox->Text = gcnew String(vacToCorrect->vacancyName.c_str());
	salaryTextBox->Text = gcnew String(vacToCorrect->salary.ToString());
	sceduleTextBox->Text = gcnew String(vacToCorrect->workingSchedule.c_str());
	trialPerTextBox->Text = gcnew String(vacToCorrect->trialPeriod.ToString());
	emailTextBox->Text = gcnew String(vacToCorrect->email.c_str());
	phoneNumberTextBox->Text = gcnew String(vacToCorrect->phoneNumber.c_str());
	reqTextBox->Text = gcnew String(InputDataValidator::join(vacToCorrect->candidateRequirement, ", ").c_str());
	logoFile = gcnew String(vacToCorrect->companyLogo.c_str());
	choosedFile = true;
}
};
}
