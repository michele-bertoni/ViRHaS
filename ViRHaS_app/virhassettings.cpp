#include "virhassettings.h"

::VirhasSettings()
{
    QCoreApplication::setOrganizationName("AIRLab Polimi"); //Organization name
    QCoreApplication::setOrganizationDomain("http://airlab.deib.polimi.it/");   //Website
    QCoreApplication::setApplicationName("ViRHaS"); //Project name
    QSettings settings; //store settings


}
