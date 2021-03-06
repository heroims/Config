//
//  Config.h
//  CloudAtlas
//
//  Created by apple on 13-3-5.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#ifndef CloudAtlas_Config_h
#define CloudAtlas_Config_h

//友盟
#define ymAppKey @""

//sina
#define kAppKey             @""
#define kAppSecret          @""
#define kAppRedirectURI     @""

//appstore id
#define APPID @""

//qq

#define QQAppID @""
#define QQKey @""
//API基址
#define baseUrl @""
//分享基址
#define baseShareUrl @""
//API基础尾椎参数
#define baseJsonLastKey @"device",@"version",@"access_token"
#define baseJsonLastValue(version,token) @"iOS",version,token

#pragma mark - 常用语句
#define NavigationBar_HEIGHT 44
#define TabBar_HEIGHT 49

//界面 尺寸不加状态栏
#define appFrame [[UIScreen mainScreen] applicationFrame]

#define appBounds [[UIScreen mainScreen] bounds]

#define appStatusBarFrame [UIApplication sharedApplication].statusBarFrame

#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width<[UIScreen mainScreen].bounds.size.height?[UIScreen mainScreen].bounds.size.width:[UIScreen mainScreen].bounds.size.height)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height>[UIScreen mainScreen].bounds.size.width?[UIScreen mainScreen].bounds.size.height:[UIScreen mainScreen].bounds.size.width)
#define SAFE_RELEASE(x) [x release];x=nil
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ([[UIDevice currentDevice] systemVersion])
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])


//use dlog to print while in debug model
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif


#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif


//ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif


//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)


#define USER_DEFAULT [NSUserDefaults standardUserDefaults]
#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]



#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }


#pragma mark - degrees/radian functions
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RGBONLYCOLOR(x) [UIColor colorWithRed:(x)/255.0 green:(x)/255.0 blue:(x)/255.0 alpha:1]
#define RGBAONLYCOLOR(x,a) [UIColor colorWithRed:(x)/255.0 green:(x)/255.0 blue:(x)/255.0 alpha:(a)]

#define ITTDEBUG
#define ITTLOGLEVEL_INFO     10
#define ITTLOGLEVEL_WARNING  3
#define ITTLOGLEVEL_ERROR    1

#ifndef ITTMAXLOGLEVEL

#ifdef DEBUG
#define ITTMAXLOGLEVEL ITTLOGLEVEL_INFO
#else
#define ITTMAXLOGLEVEL ITTLOGLEVEL_ERROR
#endif

#endif

// The general purpose logger. This ignores logging levels.
#ifdef ITTDEBUG
#define ITTDPRINT(xx, ...)  NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define ITTDPRINT(xx, ...)  ((void)0)
#endif

// Prints the current method's name.
#define ITTDPRINTMETHODNAME() ITTDPRINT(@"%s", __PRETTY_FUNCTION__)

// Log-level based logging macros.
#if ITTLOGLEVEL_ERROR <= ITTMAXLOGLEVEL
#define ITTDERROR(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDERROR(xx, ...)  ((void)0)
#endif

#if ITTLOGLEVEL_WARNING <= ITTMAXLOGLEVEL
#define ITTDWARNING(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDWARNING(xx, ...)  ((void)0)
#endif

#if ITTLOGLEVEL_INFO <= ITTMAXLOGLEVEL
#define ITTDINFO(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDINFO(xx, ...)  ((void)0)
#endif

#ifdef ITTDEBUG
#define ITTDCONDITIONLOG(condition, xx, ...) { if ((condition)) { \
ITTDPRINT(xx, ##__VA_ARGS__); \
} \
} ((void)0)
#else
#define ITTDCONDITIONLOG(condition, xx, ...) ((void)0)
#endif

#define ITTAssert(condition, ...)                                       \
do {                                                                      \
if (!(condition)) {                                                     \
[[NSAssertionHandler currentHandler]                                  \
handleFailureInFunction:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
file:[NSString stringWithUTF8String:__FILE__]  \
lineNumber:__LINE__                                  \
description:__VA_ARGS__];                             \
}                                                                       \
} while(0)



#define _po(o) DLOG(@"%@", (o))
#define _pn(o) DLOG(@"%d", (o))
#define _pf(o) DLOG(@"%f", (o))
#define _ps(o) DLOG(@"CGSize: {%.0f, %.0f}", (o).width, (o).height)
#define _pr(o) DLOG(@"NSRect: {{%.0f, %.0f}, {%.0f, %.0f}}", (o).origin.x, (o).origin.x, (o).size.width, (o).size.height)

#define DOBJ(obj)  DLOG(@"%s: %@", #obj, [(obj) description])

#define MARK    NSLog(@"\nMARK: %s, %d", __PRETTY_FUNCTION__, __LINE__)

#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]

#define   ScreenWidth   [[UIScreen mainScreen] bounds].size.width
#define  ScreenHeight  [[UIScreen mainScreen] bounds].size.height

// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define alertContent(content) \
UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" \
message:content \
delegate:nil   \
cancelButtonTitle:@"确定" \
otherButtonTitles:nil];  \
[alert show];  \
[alert release];

//单例化一个类
//头文件
#define SYNTHESIZE_SINGLETON_FOR_CLASS_HEADER(__CLASSNAME__) \
\
+ (__CLASSNAME__*) sharedInstance; \
+ (void) purgeSharedInstance;
//类文件
#define SYNTHESIZE_SINGLETON_FOR_CLASS(__CLASSNAME__) \
\
static volatile __CLASSNAME__* _##__CLASSNAME__##_sharedInstance = nil; \
\
+ (__CLASSNAME__*) sharedInstanceNoSynch \
{ \
return (__CLASSNAME__*) _##__CLASSNAME__##_sharedInstance; \
} \
\
+ (__CLASSNAME__*) sharedInstanceSynch \
{ \
@synchronized(self) \
{ \
if(nil == _##__CLASSNAME__##_sharedInstance) \
{ \
_##__CLASSNAME__##_sharedInstance = [[self alloc] init]; \
} \
else \
{ \
NSAssert2(1==0, @"SynthesizeSingleton: %@ ERROR: +(%@ *)sharedInstance method did not get swizzled.", self, self); \
} \
} \
return (__CLASSNAME__*) _##__CLASSNAME__##_sharedInstance; \
} \
\
+ (__CLASSNAME__*) sharedInstance \
{ \
return [self sharedInstanceSynch]; \
} \
\
+ (id)allocWithZone:(NSZone*) zone \
{ \
@synchronized(self) \
{ \
if (nil == _##__CLASSNAME__##_sharedInstance) \
{ \
_##__CLASSNAME__##_sharedInstance = [super allocWithZone:zone]; \
if(nil != _##__CLASSNAME__##_sharedInstance) \
{ \
Method newSharedInstanceMethod = class_getClassMethod(self, @selector(sharedInstanceNoSynch)); \
method_setImplementation(class_getClassMethod(self, @selector(sharedInstance)), method_getImplementation(newSharedInstanceMethod)); \
method_setImplementation(class_getInstanceMethod(self, @selector(retainCount)), class_getMethodImplementation(self, @selector(retainCountDoNothing))); \
method_setImplementation(class_getInstanceMethod(self, @selector(release)), class_getMethodImplementation(self, @selector(releaseDoNothing))); \
method_setImplementation(class_getInstanceMethod(self, @selector(autorelease)), class_getMethodImplementation(self, @selector(autoreleaseDoNothing))); \
} \
} \
} \
return _##__CLASSNAME__##_sharedInstance; \
} \
\
+ (void)purgeSharedInstance \
{ \
@synchronized(self) \
{ \
if(nil != _##__CLASSNAME__##_sharedInstance) \
{ \
Method newSharedInstanceMethod = class_getClassMethod(self, @selector(sharedInstanceSynch)); \
method_setImplementation(class_getClassMethod(self, @selector(sharedInstance)), method_getImplementation(newSharedInstanceMethod)); \
method_setImplementation(class_getInstanceMethod(self, @selector(retainCount)), class_getMethodImplementation(self, @selector(retainCountDoSomething))); \
method_setImplementation(class_getInstanceMethod(self, @selector(release)), class_getMethodImplementation(self, @selector(releaseDoSomething))); \
method_setImplementation(class_getInstanceMethod(self, @selector(autorelease)), class_getMethodImplementation(self, @selector(autoreleaseDoSomething))); \
[_##__CLASSNAME__##_sharedInstance release]; \
_##__CLASSNAME__##_sharedInstance = nil; \
} \
} \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
} \
\
- (id)retain \
{ \
return self; \
} \
\
- (NSUInteger)retainCount \
{ \
NSAssert1(1==0, @"SynthesizeSingleton: %@ ERROR: -(NSUInteger)retainCount method did not get swizzled.", self); \
return NSUIntegerMax; \
} \
\
- (NSUInteger)retainCountDoNothing \
{ \
return NSUIntegerMax; \
} \
- (NSUInteger)retainCountDoSomething \
{ \
return [super retainCount]; \
} \
\
- (void)release \
{ \
NSAssert1(1==0, @"SynthesizeSingleton: %@ ERROR: -(void)release method did not get swizzled.", self); \
} \
\
- (void)releaseDoNothing{} \
\
- (void)releaseDoSomething \
{ \
@synchronized(self) \
{ \
[super release]; \
} \
} \
\
- (id)autorelease \
{ \
NSAssert1(1==0, @"SynthesizeSingleton: %@ ERROR: -(id)autorelease method did not get swizzled.", self); \
return self; \
} \
\
- (id)autoreleaseDoNothing \
{ \
return self; \
} \
\
- (id)autoreleaseDoSomething \
{ \
return [super autorelease]; \
}

#endif
