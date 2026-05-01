#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysctl.h>

#define GREEN "\033[0;32m"
#define CYAN  "\033[0;36m"
#define RESET "\033[0m"

// Получение строки через sysctl
void sysctl_str(const char *name, char *buffer, size_t size) {
    size_t len = size;
    if (sysctlbyname(name, buffer, &len, NULL, 0) != 0) {
        snprintf(buffer, size, "unknown");
    }
}

// Получение int через sysctl
int sysctl_int(const char *name) {
    int value = 0;
    size_t size = sizeof(value);
    if (sysctlbyname(name, &value, &size, NULL, 0) != 0) {
        return -1;
    }
    return value;
}

// Получение uint64 через sysctl
long long sysctl_ll(const char *name) {
    long long value = 0;
    size_t size = sizeof(value);
    if (sysctlbyname(name, &value, &size, NULL, 0) != 0) {
        return -1;
    }
    return value;
}

int main() {
    char os[64] = "macOS";
    char kernel[128];
    char cpu[256];
    char model[256];
    char hostname[256];

    // Kernel
    struct utsname u;
    if (uname(&u) == 0) {
        snprintf(kernel, sizeof(kernel), "%s", u.release);
    } else {
        strcpy(kernel, "unknown");
    }

    // CPU model
    sysctl_str("machdep.cpu.brand_string", cpu, sizeof(cpu));

    // Machine model (MacBook, iMac...)
    sysctl_str("hw.model", model, sizeof(model));

    // CPU cores
    int cores = sysctl_int("hw.ncpu");

    // RAM (bytes → GB)
    long long ram_bytes = sysctl_ll("hw.memsize");
    long long ram_gb = ram_bytes / 1024 / 1024 / 1024;

    // Hostname
    gethostname(hostname, sizeof(hostname));

    // User + shell
    char *user = getenv("USER");
    char *shell = getenv("SHELL");

    // Uptime (через sysctl)
    struct timeval boottime;
    size_t size = sizeof(boottime);
    time_t now;
    time(&now);

    sysctlbyname("kern.boottime", &boottime, &size, NULL, 0);
    long uptime = now - boottime.tv_sec;

    long hours = uptime / 3600;
    long minutes = (uptime % 3600) / 60;

    // OUTPUT
    printf(CYAN);
    printf("      .:'\n");
    printf("  __ :'__\n");
    printf(".'`_  `_'  `.\n");
    printf(": (_) (_)  :   mini-fetch\n");
    printf("'.       .'\n");
    printf("  `'''''`\n");
    printf(RESET "\n");

    printf(GREEN "User: %s\n" RESET, user ? user : "unknown");
    printf(GREEN "Host: %s\n" RESET, hostname);
    printf(GREEN "OS: %s\n" RESET, os);
    printf(GREEN "Kernel: %s\n" RESET, kernel);
    printf(GREEN "Model: %s\n" RESET, model);
    printf(GREEN "CPU: %s\n" RESET, cpu);
    printf(GREEN "Cores: %d\n" RESET, cores);
    printf(GREEN "RAM: %lld GB\n" RESET, ram_gb);
    printf(GREEN "Shell: %s\n" RESET, shell ? shell : "unknown");
    printf(GREEN "Uptime: %ldh %ldm\n" RESET, hours, minutes);

    return 0;
}