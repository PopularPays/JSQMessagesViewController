//
//  Created by Jesse Squires
//  http://www.hexedbits.com
//
//
//  Documentation
//  http://cocoadocs.org/docsets/JSMessagesViewController
//
//
//  The MIT License
//  Copyright (c) 2014 Jesse Squires
//  http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

#import "JSQMessagesCollectionView.h"
#import "JSQMessagesCollectionViewFlowLayout.h"

@class JSQMessagesViewController;
@class JSQMessagesInputToolbar;
@class JSQMessage;


@interface JSQMessagesViewController : UIViewController <JSQMessagesCollectionViewDataSource,
                                                         JSQMessagesCollectionViewFlowLayoutDelegate>

@property (weak, nonatomic, readonly) JSQMessagesCollectionView *collectionView;

@property (weak, nonatomic, readonly) JSQMessagesCollectionViewFlowLayout *collectionViewLayout;

@property (weak, nonatomic, readonly) JSQMessagesInputToolbar *inputToolbar;

/**
 *  The name of the user sending messages. The default value is `@"JSQDefaultSender"`.
 */
@property (copy, nonatomic) NSString *sender;

@property (assign, nonatomic) BOOL autoScrollsToMostRecentMessage;

@property (copy, nonatomic) NSString *outgoingCellIdentifier;

@property (copy, nonatomic) NSString *incomingCellIdentifier;

#pragma mark - Class methods

+ (UINib *)nib;

+ (instancetype)messagesViewController;

#pragma mark - Initialization

- (void)prepareMessagesViewController;

#pragma mark - Messages view controller

- (void)didPressSendButton:(UIButton *)sender withMessage:(JSQMessage *)message;

- (void)didPressAccessoryButton:(UIButton *)sender;

- (void)finishSending;

- (void)scrollToBottomAnimated:(BOOL)animated;

@end