/* UICompositeViewController.h
 *
 * Copyright (C) 2012  Belledonne Comunications, Grenoble, France
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#import "LinphoneManager.h"
#import "TPMultiLayoutViewController.h"
#import "SideMenuTableView.h"

@interface UICompositeViewDescription : NSObject {
}

@property(strong) NSString *content;
@property(strong) NSString *stateBar;
@property(strong) NSString *tabBar;
@property(assign) BOOL fullscreen;
@property(assign) BOOL landscapeMode;
@property(assign) BOOL portraitMode;
@property(assign) BOOL darkBackground;

- (id)copy;
- (BOOL)equal:(UICompositeViewDescription *)description;
- (id)init:(Class)content
		 stateBar:(Class)stateBar
		   tabBar:(Class)tabBar
	   fullscreen:(BOOL)fullscreen
	landscapeMode:(BOOL)landscapeMode
	 portraitMode:(BOOL)portraitMode;

@end

@protocol UICompositeViewDelegate <NSObject>

+ (UICompositeViewDescription *)compositeViewDescription;

@end

@interface UICompositeView : TPMultiLayoutViewController {
  @private
	NSMutableDictionary *viewControllerCache;
	UICompositeViewDescription *currentViewDescription;
	UIInterfaceOrientation currentOrientation;
}

@property(strong) CATransition *viewTransition;

@property(nonatomic, strong) IBOutlet UIView *stateBarView;
@property(nonatomic, strong) IBOutlet UIView *contentView;
@property(nonatomic, strong) IBOutlet UIView *tabBarView;
@property(strong, nonatomic) IBOutlet UIView *sideMenuView;

- (void)changeView:(UICompositeViewDescription *)description;
- (void)setFullScreen:(BOOL)enabled;
- (void)hideStateBar:(BOOL)hidden;
- (void)hideToolBar:(BOOL)hidden;
- (void)hideSideMenu:(BOOL)hidden;
- (BOOL)currentViewSupportsLandscape;
- (UIViewController *)getCachedController:(NSString *)name;
- (UIViewController *)getCurrentViewController;
- (UIInterfaceOrientation)currentOrientation;
- (void)clearCache:(NSArray *)exclude;
- (IBAction)onRightSwipe:(id)sender;

@end