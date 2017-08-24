/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Elf64.h
 * Author: linhdh
 *
 * Created on August 24, 2017, 6:51 AM
 */

#ifndef ELF64_H
#define ELF64_H
#include "define.h"

#ifdef __cplusplus
extern "C" {
#endif
    
#define Elf64_Half  unsigned short int
#define Elf64_Sword int
#define Elf64_Word  unsigned int
#define Elf64_Addr  unsigned long long int
#define Elf64_Off   unsigned long long int

typedef struct {
    Elf64_Word  p_type;
    Elf64_Off   p_offset;
    Elf64_Addr  p_vaddr;
    Elf64_Addr  p_paddr;
    Elf64_Word  p_filesz;
    Elf64_Word  p_memsz;
    Elf64_Word  p_flags;
    Elf64_Word  p_align;
} Elf64_Phdr;

typedef struct {
    Elf64_Addr  r_offset;
    Elf64_Word  r_info;
} Elf64_Rel;

typedef struct {
    Elf64_Addr  r_offset;
    Elf64_Word  r_info;
    Elf64_Sword r_addend;
} Elf64_Rela;

typedef struct {
    Elf64_Word  st_name;
    Elf64_Addr  st_value;
    Elf64_Word  st_size;
    unsigned char   st_info;
    unsigned char   st_other;
    Elf64_Half      st_shndx;
} Elf64_Sym;

typedef struct {
    Elf64_Word  sh_name;
    Elf64_Word  sh_type;
    Elf64_Word  sh_flags;
    Elf64_Addr  sh_addr;
    Elf64_Off   sh_offset;
    Elf64_Word  sh_size;
    Elf64_Word  sh_link;
    Elf64_Word  sh_info;
    Elf64_Word  sh_addralign;
    Elf64_Word  sh_entsize;
} Elf64_Shdr;

typedef struct {
    unsigned char   e_ident[EI_NIDENT];
    Elf64_Half      e_type;
    Elf64_Half      e_machine;
    Elf64_Word      e_version;
    Elf64_Addr      e_entry;
    Elf64_Off       e_phoff;
    Elf64_Off       e_shoff;
    Elf64_Word      e_flags;
    Elf64_Half      e_ehsize;
    Elf64_Half      e_phentsize;
    Elf64_Half      e_phnum;
    Elf64_Half      e_shentsize;
    Elf64_Half      e_shnum;
    Elf64_Half      e_shstrndx;
} Elf64_Ehdr;

//function prototypes:
void readELF64Header(FILE *fp, Elf64_Ehdr *elfHeaderp);
void printELF64Header(Elf64_Ehdr *elfHeaderp);

#ifdef __cplusplus
}
#endif

#endif /* ELF64_H */

