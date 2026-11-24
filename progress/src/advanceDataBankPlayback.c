extern u8 *gAudioVoiceTable;
#define FIELD(p, T, off) (*(T *)((p) + (off)))
void voiceResetSlot(s32 index) ;
                                
                                  
                  
                             
                                    
                      
                        
                
                                               
                                               
                           
                                       
                                       
                                           
                                           
         
     
 

/* Advances a playing data bank by up to ticks units (clamped to its end), counts down the stop timer, and returns the amount consumed. */ u32 advanceDataBankPlayback(u8 *player, u32 ticks) {
    s32 remaining, next;
    u32 progress, delta, advance;
    if ((s8)player[0x11dd] == 3) {
        if (FIELD(player, s32, 0x11a8) > 0 && (FIELD(player, s32, 0x11a8) -= ticks) <= 0) {
                player[0x11dd] = 4;
                FIELD(player, s32, 0x11a8) = 0;
        }
        progress = FIELD(player, u32, 0x11d4);
        delta = FIELD(player, u32, 0x11d8) - progress;
    if (ticks < delta) {
        advance = ticks;
    } else {
        advance = delta;
    }
    FIELD(player, u32, 0x11d4) = progress + advance;
        return advance;
    }
    return 0;
}

void guMtxL2F(f32 *out, u32 *in) ;
                      
        
                      
                      
                                              
                                          
                                                 
                                                  
                       
                        
             
                 
                        
 

typedef struct ListNode ListNode;
struct ListNode {
    ListNode *next;
};

ListNode *__osPopThread(ListNode **head) ;
                           
                       
                
 
