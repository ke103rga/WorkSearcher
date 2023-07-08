#include <msclr\marshal_cppstd.h>
#include <unordered_set>
#include <vector>
#include <format>
#include <iostream>
#include "Vacancies.h"
#include "InputDataValidator.h"

#pragma once

namespace WorkSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace std;

	/// <summary>
	/// Сводка для CandidateWindow
	/// </summary>
	public ref class CandidateWindow : public System::Windows::Forms::Form
	{
	public:
		CandidateWindow(void)
		{
			InitializeComponent();
			for (int i = 0; i < sceduleCheckedListBox->Items->Count; i++)
				sceduleCheckedListBox->SetItemChecked(i, true);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CandidateWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ LogoPictureBox;
	private: System::Windows::Forms::LinkLabel^ helpLinkLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ vacancyNameTextBox;

	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ maxSalaryTextBox;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ minSalaryTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::CheckedListBox^ sceduleCheckedListBox;
	private: System::Windows::Forms::DataGridView^ vacanciesGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ companyName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vacancyName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ salary;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ scedule;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ trialPeriod;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contacts;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ condidateRequirments;
	private: System::Windows::Forms::DataGridViewImageColumn^ companyLogoColumn;




































	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CandidateWindow::typeid));
			this->LogoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->helpLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->vacancyNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->maxSalaryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->minSalaryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sceduleCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->vacanciesGridView = (gcnew System::Windows::Forms::DataGridView());
			this->companyName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vacancyName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->salary = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->scedule = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->trialPeriod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contacts = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->condidateRequirments = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->companyLogoColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vacanciesGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// LogoPictureBox
			// 
			this->LogoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoPictureBox.Image")));
			this->LogoPictureBox->Location = System::Drawing::Point(12, 12);
			this->LogoPictureBox->Name = L"LogoPictureBox";
			this->LogoPictureBox->Size = System::Drawing::Size(70, 63);
			this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LogoPictureBox->TabIndex = 3;
			this->LogoPictureBox->TabStop = false;
			// 
			// helpLinkLabel
			// 
			this->helpLinkLabel->AutoSize = true;
			this->helpLinkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->helpLinkLabel->LinkColor = System::Drawing::Color::DimGray;
			this->helpLinkLabel->Location = System::Drawing::Point(9, 89);
			this->helpLinkLabel->Name = L"helpLinkLabel";
			this->helpLinkLabel->Size = System::Drawing::Size(58, 16);
			this->helpLinkLabel->TabIndex = 4;
			this->helpLinkLabel->TabStop = true;
			this->helpLinkLabel->Text = L"Помощь";
			this->helpLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &CandidateWindow::helpLinkLabel_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(143, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(265, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Укажите название вакансии";
			// 
			// vacancyNameTextBox
			// 
			this->vacancyNameTextBox->Location = System::Drawing::Point(146, 55);
			this->vacancyNameTextBox->Name = L"vacancyNameTextBox";
			this->vacancyNameTextBox->Size = System::Drawing::Size(280, 20);
			this->vacancyNameTextBox->TabIndex = 6;
			// 
			// searchButton
			// 
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->searchButton->Location = System::Drawing::Point(441, 44);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(102, 40);
			this->searchButton->TabIndex = 7;
			this->searchButton->Text = L"Найти";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &CandidateWindow::searchButton_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->sceduleCheckedListBox);
			this->panel1->Location = System::Drawing::Point(0, 125);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(212, 266);
			this->panel1->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(6, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Режим работы";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->maxSalaryTextBox);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->minSalaryTextBox);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(1, 53);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(209, 105);
			this->panel2->TabIndex = 6;
			// 
			// maxSalaryTextBox
			// 
			this->maxSalaryTextBox->Location = System::Drawing::Point(39, 65);
			this->maxSalaryTextBox->Name = L"maxSalaryTextBox";
			this->maxSalaryTextBox->Size = System::Drawing::Size(100, 20);
			this->maxSalaryTextBox->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(8, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"До:";
			// 
			// minSalaryTextBox
			// 
			this->minSalaryTextBox->Location = System::Drawing::Point(39, 32);
			this->minSalaryTextBox->Name = L"minSalaryTextBox";
			this->minSalaryTextBox->Size = System::Drawing::Size(100, 20);
			this->minSalaryTextBox->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 32);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 16);
			this->label4->TabIndex = 2;
			this->label4->Text = L"От:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 16);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Зарплата";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 32);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Дополнительные\nпараметры";
			// 
			// sceduleCheckedListBox
			// 
			this->sceduleCheckedListBox->BackColor = System::Drawing::SystemColors::Control;
			this->sceduleCheckedListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->sceduleCheckedListBox->FormattingEnabled = true;
			this->sceduleCheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"5/2", L"2/2", L"посуточный ", L"почасовой" });
			this->sceduleCheckedListBox->Location = System::Drawing::Point(12, 186);
			this->sceduleCheckedListBox->Name = L"sceduleCheckedListBox";
			this->sceduleCheckedListBox->Size = System::Drawing::Size(128, 60);
			this->sceduleCheckedListBox->TabIndex = 8;
			// 
			// vacanciesGridView
			// 
			this->vacanciesGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->vacanciesGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->companyName,
					this->vacancyName, this->salary, this->scedule, this->trialPeriod, this->contacts, this->condidateRequirments, this->companyLogoColumn
			});
			this->vacanciesGridView->Location = System::Drawing::Point(218, 125);
			this->vacanciesGridView->Name = L"vacanciesGridView";
			this->vacanciesGridView->Size = System::Drawing::Size(839, 342);
			this->vacanciesGridView->TabIndex = 9;
			// 
			// companyName
			// 
			this->companyName->HeaderText = L"Компания";
			this->companyName->Name = L"companyName";
			// 
			// vacancyName
			// 
			this->vacancyName->HeaderText = L"Вакансия";
			this->vacancyName->Name = L"vacancyName";
			// 
			// salary
			// 
			this->salary->HeaderText = L"Зарплата";
			this->salary->Name = L"salary";
			// 
			// scedule
			// 
			this->scedule->HeaderText = L"График";
			this->scedule->Name = L"scedule";
			// 
			// trialPeriod
			// 
			this->trialPeriod->HeaderText = L"Исытательный срок";
			this->trialPeriod->Name = L"trialPeriod";
			// 
			// contacts
			// 
			this->contacts->HeaderText = L"Контакты";
			this->contacts->Name = L"contacts";
			// 
			// condidateRequirments
			// 
			this->condidateRequirments->HeaderText = L"Требования";
			this->condidateRequirments->Name = L"condidateRequirments";
			// 
			// companyLogoColumn
			// 
			this->companyLogoColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->companyLogoColumn->HeaderText = L"Логотип компании";
			this->companyLogoColumn->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->companyLogoColumn->Name = L"companyLogoColumn";
			// 
			// CandidateWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1069, 484);
			this->Controls->Add(this->vacanciesGridView);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->vacancyNameTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->helpLinkLabel);
			this->Controls->Add(this->LogoPictureBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"CandidateWindow";
			this->Text = L"Поиск работы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vacanciesGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


private: System::Void helpLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	String^ helpMessage = "Введите название интересующей вас вакансии и нажмите кнопку \"Найти\".\nПри необходимости укажите дополнительные параметры поиска\nи вновь нажмите кнопку \"Найти\"";
	MessageBox::MessageBox::Show(helpMessage, L"У тебя какие-то проблемы?", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string _vacancyName = msclr::interop::marshal_as<std::string>(vacancyNameTextBox->Text);
	vacanciesGridView->Rows->Clear();
	if (_vacancyName == "") {
		String^ errorMessage = "Укажите название вакансии";
		MessageBox::MessageBox::Show(errorMessage, L"У тебя какие-то проблемы?", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	int minSalary = 0;
	int maxSalary = 2^31 - 1;

	if (minSalaryTextBox->Text != "") {
		if (!InputDataValidator::isInt(minSalaryTextBox->Text)) {
			String^ errorMessage = "Границы заработной платы должны быть целыми числами";
			MessageBox::MessageBox::Show(errorMessage, L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			minSalaryTextBox->Text = "";
			return;
		}
		else {
			minSalary = Convert::ToInt32(minSalaryTextBox->Text);
			cout << minSalary;
		}
	}

	if (maxSalaryTextBox->Text != "") {
		if (!InputDataValidator::isInt(maxSalaryTextBox->Text)) {
			String^ errorMessage = "Границы заработной платы должны быть целыми числами";
			MessageBox::MessageBox::Show(errorMessage, L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			maxSalaryTextBox->Text = "";
			return;
		}
		else {
			maxSalary = Convert::ToInt32(maxSalaryTextBox->Text);
		}
	}

	if (sceduleCheckedListBox->CheckedItems->Count == 0) {
		String^ errorMessage = "Выберете хотя бы один интересующий вас график работы";
		MessageBox::MessageBox::Show(errorMessage, L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	std::unordered_set<std::string> appropriateScedules; 
	for (int i = 0; i != sceduleCheckedListBox->CheckedItems->Count; i++) {
		appropriateScedules.insert(msclr::interop::marshal_as<std::string>(sceduleCheckedListBox->CheckedItems[i]->ToString()));
	}

    std::vector<int> vacIds = vacancies.findByParams(_vacancyName, minSalary, maxSalary, appropriateScedules);
	if (vacIds.empty()) {
		String^ sadMessage = "По вашему запросу не нашлось ни одной вакансии\nНо вы не отчаивайтесь.";
		MessageBox::MessageBox::Show(sadMessage, L"Не повезло", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	/*std::vector<int> vacIds = vector<int>();
	vacIds = { 1, 2 };*/

	for (int i = 0; i != vacIds.size(); i++) {
	    Vacancy* vac = vacancies.findById(vacIds[i]);
		if (!vac) { continue;  }
	    auto arr = gcnew cli::array<Object^>(10);

	    string req = InputDataValidator::join(vac->candidateRequirement, ", ");
	    Bitmap^ logo = gcnew Bitmap(gcnew String(vac->companyLogo.c_str()));
		string contacts = "Email: " + vac->email + "\nPhone number: " + vac->phoneNumber;

	    arr[0] = gcnew String(vac->company.c_str());
	    arr[1] = gcnew String(vac->vacancyName.c_str());
	    arr[2] = gcnew String(vac->salary.ToString()); 
	    arr[3] = gcnew String(vac->workingSchedule.c_str()); 
	    arr[4] = gcnew String(vac->trialPeriod.ToString());  
	    arr[5] = gcnew String(contacts.c_str()); 
	    arr[6] = gcnew String(req.c_str());
	    arr[7] = logo;
		vacanciesGridView->Rows->Add(arr);
	}
}
};
}
