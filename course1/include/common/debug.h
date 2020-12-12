 *****************************************************************************/
/**
 * @file debug.h
 * @brief Debug printing
 *
 * Declare the function used to debug the prinf option
 *
 * @author Andrea Alvarez
 * @date 12/12/2020
 *
 */
 
 #include <stdint.h>

#ifndef debug_h_
#define debug_h_ 

   /**
 * @brief Print memory
 *
 * Takes a pinter to memory and lenght to print the hex output.
 *
 * @param beginning Pointer to start
 * @param lenght Number of bytes
 *
 */
void print_memory(uint8_t *beginning, uint32_t lenght);
 
#endif
