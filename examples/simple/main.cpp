#include <QDebug>
#include <QCoreApplication>
#include <QHttpResponseHeader>
#include <QHttpRequestHeader>
#include <QTcpSocket>

#include <application.h>
#include <server.h>
#include <httpserver.h>
#include <uniform.h>

class RootResource : public Uniform {
    virtual void get(const QHttpRequestHeader& header, QTcpSocket* out) {
        qDebug() << "Called RootResource";
        QHttpResponseHeader resp;
        QTextStream stream(out);
        stream << resp.toString() << "\r\n<h1>Test</h1>";
    }
};

class SimpleApplication : public Application {
    virtual Router* createRoot() {
        Router* r = new Router();
        r->attach("/resource", new RootResource());
        return r;
    }
};

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    
    Server* server = new HTTPServer(8080);
    RootResource rootResource;
    server->attach("/simple", new SimpleApplication());
    server->start();
    
    return app.exec();
}