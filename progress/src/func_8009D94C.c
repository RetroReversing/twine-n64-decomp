extern u8 *gAudioVoiceTable;
#define FIELD(p, T, off) (*(T *)((p) + (off)))
void voiceResetSlot(s32 index) ;
                                
                                  
                  
                             
                                    
                      
                        
                
                                               
                                               
                           
                                       
                                       
                                           
                                           
         
     
 

u32 func_8009D94C(u8 *state, u32 step) {
    s32 remaining, next;
    u32 progress, delta, advance;
    if ((s8)state[0x11dd] == 3) {
        if (FIELD(state, s32, 0x11a8) > 0 && (FIELD(state, s32, 0x11a8) -= step) <= 0) {
                state[0x11dd] = 4;
                FIELD(state, s32, 0x11a8) = 0;
        }
        progress = FIELD(state, u32, 0x11d4);
        delta = FIELD(state, u32, 0x11d8) - progress;
    if (step < delta) {
        advance = step;
    } else {
        advance = delta;
    }
    FIELD(state, u32, 0x11d4) = progress + advance;
        return advance;
    }
    return 0;
}

void func_800A97A0(f32 *out, u32 *in) ;
                      
        
                      
                      
                                              
                                          
                                                 
                                                  
                       
                        
             
                 
                        
 

typedef struct ListNode ListNode;
struct ListNode {
    ListNode *next;
};

ListNode *__osPopThread(ListNode **head) ;
                           
                       
                
 
