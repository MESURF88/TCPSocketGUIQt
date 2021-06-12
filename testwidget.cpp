#ifdef _WIN32
  #include "windows.h"
#else
  #include <unistd.h>
#endif
#include <QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSlider>

#include "UDPClient.h"
#include "guitest.h"

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        if (!qstrcmp(argv[i], "--no-gui"))
            return new QCoreApplication(argc, argv);
    }
    return new QApplication(argc, argv);
}

int main(int argc, char *argv[ ])
{
    //QScopedPointer<QCoreApplication> app(createApplication(argc, argv));
	QCoreApplication *app = createApplication(argc, argv);

    if (qobject_cast<QApplication *>(app)) {
		// start GUI version...
		printf("GUI\n");

		// Move to guiThread class
		GuiThread* gui = new GuiThread;
		gui->startThread();
		QWidget *window = new QWidget();
		QGridLayout *layout1 = new QGridLayout();
		QLabel *hello = new QLabel;
		hello->setText("<center>Hello World!</center>");
		QPushButton *quitButton = new QPushButton("Quit");
    quitButton->setAutoDefault(false);
		layout1->addWidget(hello);
		layout1->addWidget(quitButton);

		window->setWindowTitle("UDP Socket GUI");
		window->resize(800, 800);
		window->setLayout(layout1);

		window->show();

    const QString IP =     "127.0.0.1";
    const ushort port = 8000;
    EchoClient *client = new EchoClient(IP, port );
    client->startThread();

    } else {
		// start non-GUI version...
		printf("Terminal GUI\n");

    const QString IP =     "127.0.0.1";
    const ushort port = 8000;
    EchoClient *client = new EchoClient(IP, port );
    client->startThread();

    }


	return app->exec();

}
