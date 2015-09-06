#import <Foundation/Foundation.h>

@interface CookieJar : NSObject

@property (strong, atomic) NSHTTPCookieStorage *cookieStorage;
@property (strong) NSMutableDictionary *dataAccesses;
@property NSMutableDictionary *localStorage;
@property NSNumber *oldDataSweepTimeout;

- (NSArray *)sortedHostCounts;
- (BOOL)isHostWhitelisted:(NSString *)host;

- (NSArray *)cookiesForURL:(NSURL *)url forTab:(NSUInteger)tabHash;
- (void)setCookies:(NSArray *)cookies forURL:(NSURL *)URL mainDocumentURL:(NSURL *)mainDocumentURL forTab:(NSUInteger)tabHash;
- (void)trackDataAccessForDomain:(NSString *)domain fromTab:(NSUInteger)tabHash;

- (void)clearAllNonWhitelistedData;
- (void)clearAllOldNonWhitelistedData;
- (void)clearAllDataForHost:(NSString *)host;
- (void)clearNonWhitelistedDataForTab:(NSUInteger)tabHash;

@end
