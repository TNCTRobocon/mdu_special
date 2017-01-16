#ifndef APP_MID_H_
#define APP_MID_H_

#include <File.hpp>
#include <type.hpp>
namespace App {
namespace Mid{
File::Directory* Create();
File::Directory* CreateDRV();
File::Directory* CreateTrap();
File::Directory* CreatePID();

std::string Duty(const common::ShellParameter&);
std::string Free(const common::ShellParameter&);
std::string Lock(const common::ShellParameter&);
std::string CreateSwitch(const common::ShellParameter& arg);

}
} /* namespace App */

#endif /* APP_MID_H_ */
