/*
 */

#include "server.h"

#include "context.h"
#include "application.h"

void Server::attach(const QString& context, Application* app) {
    m_applications.append(app);
    Context* c = new Context(context);
    app->setContext(*c);
}

