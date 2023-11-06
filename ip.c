#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet details
void calculateSubnetDetails(char *ip, int subnet_prefix) {
    unsigned long subnet_mask = 0xFFFFFFFF << (32 - subnet_prefix);
    unsigned long ip_address = 0;
    sscanf(ip, "%lu.%lu.%lu.%lu", &ip_address, &ip_address, &ip_address, &ip_address);

    // Calculate the first address
    unsigned long first_address = ip_address & subnet_mask;

    // Calculate the last address
    unsigned long last_address = ip_address | ~subnet_mask;

    // Calculate the number of addresses
    unsigned long num_addresses = 1UL << (32 - subnet_prefix);

    printf("IP Address: %s/%d\n", ip, subnet_prefix);
    printf("Subnet Mask: %lu.%lu.%lu.%lu\n", (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
    printf("First Address: %lu.%lu.%lu.%lu\n", (first_address >> 24) & 0xFF, (first_address >> 16) & 0xFF, (first_address >> 8) & 0xFF, first_address & 0xFF);
    printf("Last Address: %lu.%lu.%lu.%lu\n", (last_address >> 24) & 0xFF, (last_address >> 16) & 0xFF, (last_address >> 8) & 0xFF, last_address & 0xFF);
    printf("Number of Addresses: %lu\n", num_addresses);
}

int main() {
    char ip[] = "194.146.24.50";
    int subnet_prefix = 25;

    calculateSubnetDetails(ip, subnet_prefix);

    return 0;
}
