//
//  RXCardProtocols.h
//  rivenx
//
//  Created by Jean-Francois Roy on 01/02/2006.
//  Copyright 2005-2012 MacStorm. All rights reserved.
//

#import "Base/RXBase.h"

#import "Rendering/RXRendering.h"
#import "Rendering/Audio/RXSoundGroup.h"
#import "Rendering/Graphics/RXTransition.h"
#import "Rendering/Graphics/RXPicture.h"
#import "Rendering/Graphics/RXMovie.h"

@class RXCard;

@protocol RXCardRendererProtocol <NSObject>
- (void)activateSoundGroup:(RXSoundGroup*)soundGroup;
- (void)playDataSound:(RXDataSound*)sound;

- (void)queuePicture:(RXPicture*)picture;

- (void)queueSpecialEffect:(rx_card_sfxe*)sfxe owner:(id)owner;
- (void)disableWaterSpecialEffect;
- (void)enableWaterSpecialEffect;

- (void)queueTransition:(RXTransition*)transition;
- (void)enableTransitionDequeueing;
- (void)disableTransitionDequeueing;

- (void)enableMovie:(RXMovie*)movie;
- (void)disableMovie:(RXMovie*)movie;
- (void)disableAllMovies;
- (void)disableAllMoviesOnNextScreenUpdate;
- (BOOL)isMovieEnabled:(RXMovie*)movie;

- (void)update;

- (void)beginEndCredits;
@end

@protocol RXCardEventsHandlerProtocol <NSObject>
- (double)mouseTimestamp;
- (rx_event_t)lastMouseDownEvent;
- (NSRect)mouseVector;
- (void)resetMouseVector;

- (void)showMouseCursor;
- (void)hideMouseCursor;
- (void)setMouseCursor:(uint16_t)cursorID;

- (void)enableHotspotHandling;
- (void)disableHotspotHandling;
- (void)updateHotspotState;
@end
