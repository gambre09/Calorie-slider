#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QVector>
#include <QFont>

class CalorieSliderApp : public QWidget {
    Q_OBJECT

public:
    CalorieSliderApp(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(15);
        mainLayout->setContentsMargins(20, 20, 20, 20);

        // -------- Calorie Budget Input Section --------
        QHBoxLayout *budgetLayout = new QHBoxLayout;
        QLabel *budgetLabel = new QLabel("Daily Maintenance Calories:");
        budgetLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        budgetInput = new QLineEdit("2000");
        budgetInput->setFixedWidth(80);
        weeklyBudgetLabel = new QLabel("Weekly Budget: 14000 cal");
        weeklyBudgetLabel->setStyleSheet("font-weight: bold");

        budgetLayout->addStretch();
        budgetLayout->addWidget(budgetLabel);
        budgetLayout->addWidget(budgetInput);
        budgetLayout->addSpacing(15);
        budgetLayout->addWidget(weeklyBudgetLabel);
        budgetLayout->addStretch();
        mainLayout->addLayout(budgetLayout);

        // -------- Sliders Section --------
        slidersLayout = new QHBoxLayout;
        slidersLayout->setSpacing(30);
        QFont sliderFont;
        sliderFont.setBold(true);

        for (int i = 0; i < 7; ++i) {
            QVBoxLayout *dayLayout = new QVBoxLayout;
            dayLayout->setAlignment(Qt::AlignCenter);

            QSlider *slider = new QSlider(Qt::Vertical);
            slider->setRange(0, 6000);
            slider->setTickInterval(100);
            slider->setSingleStep(100);
            slider->setValue(i == 6 ? 0 : 2000);
            slider->setFixedHeight(200);

            QLabel *label = new QLabel(QString("Day %1\n%2 cal").arg(i + 1).arg(slider->value()));
            label->setFont(sliderFont);
            label->setAlignment(Qt::AlignCenter);

            dayLayout->addWidget(slider);
            dayLayout->addWidget(label);

            sliders.append(slider);
            labels.append(label);

            if (i != 6) {
                connect(slider, &QSlider::valueChanged, this, &CalorieSliderApp::updateDay7);
            }

            slidersLayout->addLayout(dayLayout);
        }

        mainLayout->addLayout(slidersLayout);

        // -------- Average & Total Calories Section --------
        avgLabel = new QLabel("Average Calories/Day: 0");
        avgLabel->setAlignment(Qt::AlignCenter);
        avgLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

        totalLabel = new QLabel("Total Calories: 0");
        totalLabel->setAlignment(Qt::AlignCenter);
        totalLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

        mainLayout->addWidget(avgLabel);
        mainLayout->addWidget(totalLabel);

        // -------- Connect Input --------
        connect(budgetInput, &QLineEdit::textChanged, this, &CalorieSliderApp::updateDay7);

        updateDay7();
    }

private slots:
    void updateDay7() {
        int daily = budgetInput->text().toInt();
        int weekly = daily * 7;
        weeklyBudgetLabel->setText(QString("Weekly Budget: %1 cal").arg(weekly));

        int sum = 0;
        for (int i = 0; i < 6; ++i) {
            int val = sliders[i]->value();
            labels[i]->setText(QString("Day %1\n%2 cal").arg(i + 1).arg(val));
            sum += val;
        }

        int day7val = std::max(0, weekly - sum);
        sliders[6]->setValue(day7val);
        labels[6]->setText(QString("Day 7\n%1 cal").arg(day7val));

        int totalCalories = sum + day7val;
        double avg = totalCalories / 7.0;

        totalLabel->setText(QString("Total Calories: %1 / %2").arg(totalCalories).arg(weekly));
        avgLabel->setText(QString("Average Calories/Day: %1").arg(QString::number(avg, 'f', 1)));
    }

private:
    QLineEdit *budgetInput;
    QLabel *weeklyBudgetLabel;
    QHBoxLayout *slidersLayout;
    QLabel *totalLabel;
    QLabel *avgLabel;
    QVector<QSlider*> sliders;
    QVector<QLabel*> labels;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CalorieSliderApp window;
    window.setWindowTitle("Weekly Calorie Slider");
    window.resize(800, 600);
    window.show();
    return app.exec();
}
