/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: linhdh
 *
 * Created on August 21, 2017, 5:27 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "Elf32.h"
#include "Elf64.h"

void readELF64Header(FILE *fp, Elf64_Ehdr *elfHeaderp)
{
    fread(&elfHeaderp->e_ident, sizeof(char), EI_NIDENT, fp);
    fread(&elfHeaderp->e_type, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_machine, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_version, sizeof(Elf64_Word), 1, fp);
    fread(&elfHeaderp->e_entry, sizeof(Elf64_Addr), 1, fp);
    fread(&elfHeaderp->e_phoff, sizeof(Elf64_Off), 1, fp);
    fread(&elfHeaderp->e_shoff, sizeof(Elf64_Off), 1, fp);
    fread(&elfHeaderp->e_flags, sizeof(Elf64_Word), 1, fp);
    fread(&elfHeaderp->e_ehsize, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_phentsize, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_phnum, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_shentsize, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_shnum, sizeof(Elf64_Half), 1, fp);
    fread(&elfHeaderp->e_shstrndx, sizeof(Elf64_Half), 1, fp);            
}

void readELF32Header(FILE *fp, Elf32_Ehdr *elfHeaderp)
{
    fread(&elfHeaderp->e_ident, sizeof(char), EI_NIDENT, fp);
    fread(&elfHeaderp->e_type, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_machine, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_version, sizeof(Elf32_Word), 1, fp);
    fread(&elfHeaderp->e_entry, sizeof(Elf32_Addr), 1, fp);
    fread(&elfHeaderp->e_phoff, sizeof(Elf32_Off), 1, fp);
    fread(&elfHeaderp->e_shoff, sizeof(Elf32_Off), 1, fp);
    fread(&elfHeaderp->e_flags, sizeof(Elf32_Word), 1, fp);
    fread(&elfHeaderp->e_ehsize, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_phentsize, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_phnum, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_shentsize, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_shnum, sizeof(Elf32_Half), 1, fp);
    fread(&elfHeaderp->e_shstrndx, sizeof(Elf32_Half), 1, fp);        
}

void printELF64Header(Elf64_Ehdr *elfHeaderp)
{
    char* class[] = {"None", "ELF32", "ELF64"};
    char* data[] = {"None", "little endian", "big endian"};
    char* type[] = {"No file type", "Relocatable file", "Executable file", "Shared object file", "Core file"};
    printf("ELF Header:\n");
    printf("  Magic:    ");
    for (int i=0; i<16; i++)
        printf("%02x ", elfHeaderp->e_ident[i]);
    printf("\n");
    printf("  Class:                                %s\n", class[elfHeaderp->e_ident[EI_CLASS]]);
    printf("  Data:                                 %s\n", data[elfHeaderp->e_ident[EI_DATA]]);
    printf("  Version:                              %d\n", elfHeaderp->e_ident[EI_VERSION]);
    printf("  Type:                                 %s\n", type[elfHeaderp->e_type]);
    printf("  Machine:                              %u\n", elfHeaderp->e_machine);
    printf("  Entry point address:                  0x%x\n", elfHeaderp->e_entry);
    printf("  Start of program headers:             %u\n", elfHeaderp->e_phoff);
    printf("  Start of section headers:             %u\n", elfHeaderp->e_shoff);
    printf("  Processor-specific flags:             0x%x\n", elfHeaderp->e_flags);
    printf("  Size of this header:                  %u\n", elfHeaderp->e_ehsize);
    printf("  Size of program headers:              %u\n", elfHeaderp->e_phentsize);
    printf("  Number of program headers:            %u\n", elfHeaderp->e_phnum);
    printf("  Size of section headers:              %u\n", elfHeaderp->e_shentsize);
    printf("  Number of section headers:            %u\n", elfHeaderp->e_shnum);
    printf("  Section header string table index:    %u\n", elfHeaderp->e_shstrndx);
}

void printELF32Header(Elf32_Ehdr *elfHeaderp)
{
    char* class[] = {"None", "ELF32", "ELF64"};
    char* data[] = {"None", "little endian", "big endian"};
    char* type[] = {"No file type", "Relocatable file", "Executable file", "Shared object file", "Core file"};
    printf("ELF Header:\n");
    printf("  Magic:    ");
    for (int i=0; i<16; i++)
        printf("%02x ", elfHeaderp->e_ident[i]);
    printf("\n");
    printf("  Class:                                %s\n", class[elfHeaderp->e_ident[EI_CLASS]]);
    printf("  Data:                                 %s\n", data[elfHeaderp->e_ident[EI_DATA]]);
    printf("  Version:                              %d\n", elfHeaderp->e_ident[EI_VERSION]);
    printf("  Type:                                 %s\n", type[elfHeaderp->e_type]);
    printf("  Machine:                              %u\n", elfHeaderp->e_machine);
    printf("  Entry point address:                  0x%x\n", elfHeaderp->e_entry);
    printf("  Start of program headers:             %u\n", elfHeaderp->e_phoff);
    printf("  Start of section headers:             %u\n", elfHeaderp->e_shoff);
    printf("  Processor-specific flags:             0x%x\n", elfHeaderp->e_flags);
    printf("  Size of this header:                  %u\n", elfHeaderp->e_ehsize);
    printf("  Size of program headers:              %u\n", elfHeaderp->e_phentsize);
    printf("  Number of program headers:            %u\n", elfHeaderp->e_phnum);
    printf("  Size of section headers:              %u\n", elfHeaderp->e_shentsize);
    printf("  Number of section headers:            %u\n", elfHeaderp->e_shnum);
    printf("  Section header string table index:    %u\n", elfHeaderp->e_shstrndx);    
}

void readSectionHeader(FILE *fp, Elf32_Shdr *sectionHeaderp)
{
    fread(&sectionHeaderp->sh_name, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_type, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_flags, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_addr, sizeof(Elf32_Addr), 1, fp);
    fread(&sectionHeaderp->sh_offset, sizeof(Elf32_Off), 1, fp);
    fread(&sectionHeaderp->sh_size, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_link, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_info, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_addralign, sizeof(Elf32_Word), 1, fp);
    fread(&sectionHeaderp->sh_entsize, sizeof(Elf32_Word), 1, fp);        
}

void readProgramHeader(FILE *fp, Elf32_Phdr *programHeaderp)
{
    fread(&programHeaderp->p_type, sizeof(Elf32_Word), 1, fp);
    fread(&programHeaderp->p_offset, sizeof(Elf32_Off), 1, fp);
    fread(&programHeaderp->p_vaddr, sizeof(Elf32_Addr), 1, fp);
    fread(&programHeaderp->p_paddr, sizeof(Elf32_Addr), 1, fp);
    fread(&programHeaderp->p_filesz, sizeof(Elf32_Word), 1, fp);
    fread(&programHeaderp->p_memsz, sizeof(Elf32_Word), 1, fp);
    fread(&programHeaderp->p_flags, sizeof(Elf32_Word), 1, fp);
    fread(&programHeaderp->p_align, sizeof(Elf32_Word), 1, fp);        
}


int main(int argc, char** argv) {
    char temp[16];
    Elf32_Ehdr *e32hdrp = malloc(sizeof(Elf32_Ehdr));
    Elf64_Ehdr *e64hdrp = malloc(sizeof(Elf64_Ehdr));
    if (e32hdrp == NULL || e64hdrp == NULL) return (EXIT_FAILURE);
    FILE *fp = fopen("/home/linhdh/Documents/bash", "rb");
    if(fp == NULL) 
    {
        printf("open file error.\n");
        return (EXIT_FAILURE);
    }
    fread(&e32hdrp->e_ident, sizeof(char), EI_NIDENT, fp);
    fseek(fp, 0, SEEK_SET);
    if(e32hdrp->e_ident[EI_CLASS] == ELFCLASS64)
    {
        readELF64Header(fp, e64hdrp);
        printELF64Header(e64hdrp);
    } 
    else
    {
        readELF32Header(fp, e32hdrp);
        printELF32Header(e32hdrp);
    }        
    return (EXIT_SUCCESS);
}

