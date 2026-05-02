#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysctl.h>
#include <time.h>

#define GREEN "\033[0;32m"
#define CYAN  "\033[0;36m"
#define RESET "\033[0m"

// ===================== helpers =====================

void sysctl_str(const char *name, char *buffer, size_t size) {
    size_t len = size;
    if (sysctlbyname(name, buffer, &len, NULL, 0) != 0) {
        snprintf(buffer, size, "unknown");
    }
}

int sysctl_int(const char *name) {
    int value = 0;
    size_t size = sizeof(value);
    if (sysctlbyname(name, &value, &size, NULL, 0) != 0) {
        return -1;
    }
    return value;
}

long long sysctl_ll(const char *name) {
    long long value = 0;
    size_t size = sizeof(value);
    if (sysctlbyname(name, &value, &size, NULL, 0) != 0) {
        return -1;
    }
    return value;
}

// ===================== system info =====================

// OS
void get_os(char *buffer, size_t size) {
    snprintf(buffer, size, "macOS");
}

// Kernel
void get_kernel(char *buffer, size_t size) {
    struct utsname u;
    if (uname(&u) == 0) {
        snprintf(buffer, size, "%s", u.release);
    } else {
        snprintf(buffer, size, "unknown");
    }
}

// CPU model
void get_cpu_model(char *buffer, size_t size) {
    sysctl_str("machdep.cpu.brand_string", buffer, size);
}

// CPU cores
int get_cpu_cores() {
    return sysctl_int("hw.ncpu");
}

// RAM (GB)
long long get_ram_gb() {
    long long bytes = sysctl_ll("hw.memsize");
    return bytes / 1024 / 1024 / 1024;
}

// Machine model
void get_machine_model(char *buffer, size_t size) {
    sysctl_str("hw.model", buffer, size);
}

// Hostname
void get_hostname(char *buffer, size_t size) {
    if (gethostname(buffer, size) != 0) {
        snprintf(buffer, size, "unknown");
    }
}

// User
const char* get_user() {
    return getenv("USER");
}

// Shell
const char* get_shell() {
    return getenv("SHELL");
}

// Uptime (hours + minutes)
void get_uptime(long *hours, long *minutes) {
    struct timeval boottime;
    size_t size = sizeof(boottime);

    if (sysctlbyname("kern.boottime", &boottime, &size, NULL, 0) != 0) {
        *hours = -1;
        *minutes = -1;
        return;
    }

    time_t now;
    time(&now);

    long uptime = now - boottime.tv_sec;
    *hours = uptime / 3600;
    *minutes = (uptime % 3600) / 60;
}

// ===================== UI =====================

void print_logo() {
    printf(CYAN);
    printf("      .:'\n");
    printf("  __ :'__\n");
    printf(".'`_  `_'  `.\n");
    printf(": (_) (_)  :   mini-fetch\n");
    printf("'.       .'\n");
    printf("  `'''''`\n");
    printf(RESET "\n");
}

void print_info() {
    char os[64];
    char kernel[128];
    char cpu[256];
    char model[256];
    char hostname[256];

    get_os(os, sizeof(os));
    get_kernel(kernel, sizeof(kernel));
    get_cpu_model(cpu, sizeof(cpu));
    get_machine_model(model, sizeof(model));
    get_hostname(hostname, sizeof(hostname));

    int cores = get_cpu_cores();
    long long ram = get_ram_gb();

    long hours, minutes;
    get_uptime(&hours, &minutes);

    const char *user = get_user();
    const char *shell = get_shell();

    printf(GREEN "User: %s\n" RESET, user ? user : "unknown");
    printf(GREEN "Host: %s\n" RESET, hostname);
    printf(GREEN "OS: %s\n" RESET, os);
    printf(GREEN "Kernel: %s\n" RESET, kernel);
    printf(GREEN "Model: %s\n" RESET, model);
    printf(GREEN "CPU: %s\n" RESET, cpu);
    printf(GREEN "Cores: %d\n" RESET, cores);
    printf(GREEN "RAM: %lld GB\n" RESET, ram);
    printf(GREEN "Shell: %s\n" RESET, shell ? shell : "unknown");

    if (hours >= 0)
        printf(GREEN "Uptime: %ldh %ldm\n" RESET, hours, minutes);
    else
        printf(GREEN "Uptime: unknown\n" RESET);
}

// ===================== main =====================

int main() {
    print_logo();
    print_info();
    return 0;
}