#pragma once

#include <drogon/drogon.h>

#define server drogon::app()
#define DATABASE_CLIENT drogon::app().getDbClient()