#include <stdint.h>

/* define DRAM usecase */
#define USE_DRAM_CPU2FPGA_ONLY 0
#define USE_DRAM_FPGA2CPU_ONLY 1
#define USE_DRAM_CPU2FPGA_AND_FPGA2CPU 2

/* define DRAM modes */
#define NO_DRAM 0
#define DIRECT_DRAM 1
#define HYBRID_DRAM 2

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Send a buffer to the FPGA for a specific application
 * @param appid: The application ID
 * @param message: The message to send
 * @param len: The length of the message
 */
int rah_write(const uint8_t appid, const char* message,
		const unsigned long len);

/*
 * Read a buffer from the FPGA for a specific application
 * @param appid: The application ID
 * @param message: The message to read
 * @param len: The length of the message
 */
int rah_read(const uint8_t appid, char *message,
		const unsigned long len);

/*
 * Clear the buffer for a specific application
 * @param appid: The application ID
 */
int rah_clear_buffer(const uint8_t appid);

/*
 * Request memory for a specific application
 * @param appid: The application ID
 * @param len: The length of the memory to request
 */
void *rah_request_mem(const uint8_t appid, const unsigned long len);

/*
 * Write to memory for a specific application
 * @param appid: The application ID
 * @param ptr: The pointer to the memory
 * @param len: The length of the memory to write
 */
int rah_write_mem(const uint8_t appid, void* ptr, const unsigned long len);

/*
 * Free memory for a specific application
 * @param ptr: The pointer to the memory
 */
void rah_free_mem(void* ptr);

/*
 * Get maximum buffer size
 */
unsigned long rah_max_buffer_size(void);


/*
 * Match rah version with the FPGA
 */
int rah_check_version_compatible(void);

/*
 * Set the DRAM mode for a specific application
 * @param appid: The application ID
 * @param mode: The DRAM mode to set (NO_DRAM, DIRECT_DRAM, HYBRID_DRAM)
 */
int rah_dram_set_mode(const uint8_t appid, const uint8_t mode);

/*
 * Set the DRAM usecase for a specific application
 * @param appid: The application ID
 * @param usecase: The DRAM usecase to set
 * 	(USE_DRAM_CPU2FPGA_ONLY, USE_DRAM_FPGA2CPU_ONLY,
 *	USE_DRAM_CPU2FPGA_AND_FPGA2CPU)
 */
int rah_dram_set_usecase(const uint8_t appid, const uint8_t usecase);

/*
 * Get the DRAM mode for a specific application
 * @param appid: The application ID
 * @param mode: Pointer to store the current DRAM mode
 */
int rah_dram_get_usecase(const uint8_t appid, uint8_t *usecase);

/*
 * Allocate DRAM memory for a specific application
 * @param appid: The application ID
 * @param len: The length of the memory to allocate
 */
int rah_dram_memory_alloc(const uint8_t appid, const int len);

/*
 * Free DRAM memory for a specific application
 * @param appid: The application ID
 */
int rah_dram_memory_free(const uint8_t appid);
#ifdef __cplusplus
}
#endif
