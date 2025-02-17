/*  =========================================================================
    zpipes_msg - ZPIPES protocol
    
    Codec header for zpipes_msg.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

    * The XML model used for this code generation: zpipes_msg.xml
    * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of zbroker, the ZeroMQ broker project.           
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef __ZPIPES_MSG_H_INCLUDED__
#define __ZPIPES_MSG_H_INCLUDED__

/*  These are the zpipes_msg messages:

    INPUT - Create a new pipe for reading
        pipename            string      Name of pipe

    INPUT_OK - Input request was successful

    INPUT_FAILED - Input request failed
        reason              string      Reason for failure

    OUTPUT - Create a new pipe for writing
        pipename            string      Name of pipe

    OUTPUT_OK - Output request was successful

    OUTPUT_FAILED - Output request failed
        reason              string      Reason for failure

    READ - Read a chunk of data from pipe
        size                number 4    Number of bytes to read
        timeout             number 4    Timeout, msecs, or zero

    READ_OK - Read was successful
        chunk               chunk       Chunk of data

    READ_END - Pipe is closed, no more data

    READ_TIMEOUT - Read ended with timeout

    READ_FAILED - Read failed due to error
        reason              string      Reason for failure

    WRITE - Write chunk of data to pipe
        chunk               chunk       Chunk of data
        timeout             number 4    Timeout, msecs, or zero

    WRITE_OK - Write was successful

    WRITE_TIMEOUT - Write ended with timeout

    WRITE_FAILED - Read failed due to error
        reason              string      Reason for failure

    CLOSE - Close pipe

    CLOSE_OK - Close was successful

    CLOSE_FAILED - Close failed due to error
        reason              string      Reason for failure

    PING - Signal liveness

    PING_OK - Respond to ping

    INVALID - Command was invalid at this time
*/


#define ZPIPES_MSG_INPUT                    1
#define ZPIPES_MSG_INPUT_OK                 2
#define ZPIPES_MSG_INPUT_FAILED             3
#define ZPIPES_MSG_OUTPUT                   4
#define ZPIPES_MSG_OUTPUT_OK                5
#define ZPIPES_MSG_OUTPUT_FAILED            6
#define ZPIPES_MSG_READ                     7
#define ZPIPES_MSG_READ_OK                  8
#define ZPIPES_MSG_READ_END                 9
#define ZPIPES_MSG_READ_TIMEOUT             10
#define ZPIPES_MSG_READ_FAILED              11
#define ZPIPES_MSG_WRITE                    12
#define ZPIPES_MSG_WRITE_OK                 13
#define ZPIPES_MSG_WRITE_TIMEOUT            14
#define ZPIPES_MSG_WRITE_FAILED             15
#define ZPIPES_MSG_CLOSE                    16
#define ZPIPES_MSG_CLOSE_OK                 17
#define ZPIPES_MSG_CLOSE_FAILED             18
#define ZPIPES_MSG_PING                     19
#define ZPIPES_MSG_PING_OK                  20
#define ZPIPES_MSG_INVALID                  21

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
typedef struct _zpipes_msg_t zpipes_msg_t;

//  @interface
//  Create a new zpipes_msg
CZMQ_EXPORT zpipes_msg_t *
    zpipes_msg_new (int id);

//  Destroy the zpipes_msg
CZMQ_EXPORT void
    zpipes_msg_destroy (zpipes_msg_t **self_p);

//  Parse a zpipes_msg from zmsg_t. Returns a new object, or NULL if
//  the message could not be parsed, or was NULL. Destroys msg and 
//  nullifies the msg reference.
CZMQ_EXPORT zpipes_msg_t *
    zpipes_msg_decode (zmsg_t **msg_p);

//  Encode zpipes_msg into zmsg and destroy it. Returns a newly created
//  object or NULL if error. Use when not in control of sending the message.
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode (zpipes_msg_t **self_p);

//  Receive and parse a zpipes_msg from the socket. Returns new object, 
//  or NULL if error. Will block if there's no message waiting.
CZMQ_EXPORT zpipes_msg_t *
    zpipes_msg_recv (void *input);

//  Receive and parse a zpipes_msg from the socket. Returns new object, 
//  or NULL either if there was no input waiting, or the recv was interrupted.
CZMQ_EXPORT zpipes_msg_t *
    zpipes_msg_recv_nowait (void *input);

//  Send the zpipes_msg to the output, and destroy it
CZMQ_EXPORT int
    zpipes_msg_send (zpipes_msg_t **self_p, void *output);

//  Send the zpipes_msg to the output, and do not destroy it
CZMQ_EXPORT int
    zpipes_msg_send_again (zpipes_msg_t *self, void *output);

//  Encode the INPUT 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_input (
        const char *pipename);

//  Encode the INPUT_OK 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_input_ok (
);

//  Encode the INPUT_FAILED 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_input_failed (
        const char *reason);

//  Encode the OUTPUT 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_output (
        const char *pipename);

//  Encode the OUTPUT_OK 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_output_ok (
);

//  Encode the OUTPUT_FAILED 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_output_failed (
        const char *reason);

//  Encode the READ 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_read (
        uint32_t size,
        uint32_t timeout);

//  Encode the READ_OK 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_read_ok (
        zchunk_t *chunk);

//  Encode the READ_END 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_read_end (
);

//  Encode the READ_TIMEOUT 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_read_timeout (
);

//  Encode the READ_FAILED 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_read_failed (
        const char *reason);

//  Encode the WRITE 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_write (
        zchunk_t *chunk,
        uint32_t timeout);

//  Encode the WRITE_OK 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_write_ok (
);

//  Encode the WRITE_TIMEOUT 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_write_timeout (
);

//  Encode the WRITE_FAILED 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_write_failed (
        const char *reason);

//  Encode the CLOSE 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_close (
);

//  Encode the CLOSE_OK 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_close_ok (
);

//  Encode the CLOSE_FAILED 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_close_failed (
        const char *reason);

//  Encode the PING 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_ping (
);

//  Encode the PING_OK 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_ping_ok (
);

//  Encode the INVALID 
CZMQ_EXPORT zmsg_t *
    zpipes_msg_encode_invalid (
);


//  Send the INPUT to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_input (void *output,
        const char *pipename);
    
//  Send the INPUT_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_input_ok (void *output);
    
//  Send the INPUT_FAILED to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_input_failed (void *output,
        const char *reason);
    
//  Send the OUTPUT to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_output (void *output,
        const char *pipename);
    
//  Send the OUTPUT_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_output_ok (void *output);
    
//  Send the OUTPUT_FAILED to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_output_failed (void *output,
        const char *reason);
    
//  Send the READ to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_read (void *output,
        uint32_t size,
        uint32_t timeout);
    
//  Send the READ_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_read_ok (void *output,
        zchunk_t *chunk);
    
//  Send the READ_END to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_read_end (void *output);
    
//  Send the READ_TIMEOUT to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_read_timeout (void *output);
    
//  Send the READ_FAILED to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_read_failed (void *output,
        const char *reason);
    
//  Send the WRITE to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_write (void *output,
        zchunk_t *chunk,
        uint32_t timeout);
    
//  Send the WRITE_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_write_ok (void *output);
    
//  Send the WRITE_TIMEOUT to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_write_timeout (void *output);
    
//  Send the WRITE_FAILED to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_write_failed (void *output,
        const char *reason);
    
//  Send the CLOSE to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_close (void *output);
    
//  Send the CLOSE_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_close_ok (void *output);
    
//  Send the CLOSE_FAILED to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_close_failed (void *output,
        const char *reason);
    
//  Send the PING to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_ping (void *output);
    
//  Send the PING_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_ping_ok (void *output);
    
//  Send the INVALID to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
CZMQ_EXPORT int
    zpipes_msg_send_invalid (void *output);
    
//  Duplicate the zpipes_msg message
CZMQ_EXPORT zpipes_msg_t *
    zpipes_msg_dup (zpipes_msg_t *self);

//  Print contents of message to stdout
CZMQ_EXPORT void
    zpipes_msg_print (zpipes_msg_t *self);

//  Get/set the message routing id
CZMQ_EXPORT zframe_t *
    zpipes_msg_routing_id (zpipes_msg_t *self);
CZMQ_EXPORT void
    zpipes_msg_set_routing_id (zpipes_msg_t *self, zframe_t *routing_id);

//  Get the zpipes_msg id and printable command
CZMQ_EXPORT int
    zpipes_msg_id (zpipes_msg_t *self);
CZMQ_EXPORT void
    zpipes_msg_set_id (zpipes_msg_t *self, int id);
CZMQ_EXPORT const char *
    zpipes_msg_command (zpipes_msg_t *self);

//  Get/set the pipename field
CZMQ_EXPORT const char *
    zpipes_msg_pipename (zpipes_msg_t *self);
CZMQ_EXPORT void
    zpipes_msg_set_pipename (zpipes_msg_t *self, const char *format, ...);

//  Get/set the reason field
CZMQ_EXPORT const char *
    zpipes_msg_reason (zpipes_msg_t *self);
CZMQ_EXPORT void
    zpipes_msg_set_reason (zpipes_msg_t *self, const char *format, ...);

//  Get/set the size field
CZMQ_EXPORT uint32_t
    zpipes_msg_size (zpipes_msg_t *self);
CZMQ_EXPORT void
    zpipes_msg_set_size (zpipes_msg_t *self, uint32_t size);

//  Get/set the timeout field
CZMQ_EXPORT uint32_t
    zpipes_msg_timeout (zpipes_msg_t *self);
CZMQ_EXPORT void
    zpipes_msg_set_timeout (zpipes_msg_t *self, uint32_t timeout);

//  Get a copy of the chunk field
CZMQ_EXPORT zchunk_t *
    zpipes_msg_chunk (zpipes_msg_t *self);
//  Get the chunk field and transfer ownership to caller
CZMQ_EXPORT zchunk_t *
    zpipes_msg_get_chunk (zpipes_msg_t *self);
//  Set the chunk field, transferring ownership from caller
CZMQ_EXPORT void
    zpipes_msg_set_chunk (zpipes_msg_t *self, zchunk_t **chunk_p);

//  Self test of this class
CZMQ_EXPORT int
    zpipes_msg_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define zpipes_msg_dump     zpipes_msg_print

#ifdef __cplusplus
}
#endif

#endif
