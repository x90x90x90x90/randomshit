#include <stdio.h>

int isVMXSupported() {
    int result;
    __asm__  (
        "mov eax, 1 \n" 
        "cpuid \n" 
        "test ecx, 0x10 \n" 
        "setz al \n"     
        "movzx %[result], al \n" 
        : [result] "=r" (result) 
        :                       
        : "eax", "ebx", "edx", "ecx" // Clobbered registers
    );
    printf("result: %d \n", result);
    return result;
}

int main() {
    if (isVMXSupported()) {
        printf("VMX operation is supported on this CPU.\n");
    } else {
        printf("VMX operation is not supported on this CPU.\n");
    }
    return 0;
}
